#!/bin/sh

PHRASES="You know... Jesus never apologized for being dope as fuck either. \n
Cocaine is the most efficient weight loss program that we know of. \n
Life isn't an episode of Skins. \n
Remember: if you close your eyes it's not real. \n
People hate to see women breaking into male dominated fields (psychopathy). \n
Bad things only happen to me because I'm the main character so it's only part of the plot. \n
Hate your life? Try dissociating. \n
He said I'm not like the other girls. How does he know other girls? I can't fucking breathe. \n
Sorry for acting like that. It will happen again.\n
Don't kill yourself. You might be a MILF in the future! \n
The only way you could ever sin is if you do not believe you are the person you want to be right now. Eating ass, also. \n
Remember that everything will be okay when the worms eat your body. \n
Making art about important things doesn't make it important art. #JustSaying \n
Gaslighting isn't even real, y'all are just crazy. \n
I'm a gummy bear. Oh, I'm a gummy bear. \n
Falling in love? In this economy?! \n
I'm a dick, boy, addicted to you. \n
A mosquito can fly but a fly can not mosquito.\n
To be clear nobody has ever said \"I couldn't do it\". I tend to create haters for myself in my own head to inspire me to hustle harder. \n
I don't smoke cigs in a trashy, ruin your lungs kind of way, but instead in a 1960s French film icon, existencialist philosopher from the 1940s writing in a parisienne cafe, 90s supermodel way. \n
Claustrophobic? Who would ever be afraid of Santa Claus? \n
Americans are like \"I was a gifted child but also I didn't learn other countries existed until I was 35 years old\". \n
Y'all will write prose and then separate each sentence with the enter key and call it poetry. What the fuck is this?! \n
When he knows that you're at your lowest point so he decides to drag you down even further to show you that nothing's impossible <3 \n
I got used to toxic character ASMR play and now everytime someone is mean to me I get sleepy. \n
Basically I'm a NPC. I speak to nobody unless I'm spoken to. \n
I swear to God dude, I have good fashion sense. I'm wearing sweatpants and a hoodie not in a basic way but in a lynchian absurdist kafkaesque lovecraftian utilitarian nihilistic post modern lars von trierian way. \n
Chemistry said alcohol is a solution. \n
Water: human right or Nestlé's?\n
Radiohead was right. I'm a creep. I'm a weirdo. What the hell. \n
How are you gonna tell me the world was just water and rocks and a motherfucker made Bluetooth outta that? \n
Ex:Re was right. He will. He will. You know. You know. \n
Sometimes all you gotta do is go to the forest and scream like a cicada. \n
Even artichokes have hearts.\n
You are not a goddamn pigeon to hold yourself onto crumbs. Stop. \n
It’s hard to explain puns to kleptomaniacs because they always take things literally. \n
How many Freudians does it take to change a lightbulb? Two. One to change the bulb and one to hold the penis - I MEAN LADDER! \n
ERWIN SCHRODINGER MAY OR MAY NOT BE A PUSSY. \n
Rick Astley will let you borrow any movie from his Pixar collection, except one. He's never gonna give you Up.\n
Electra Heart is kinda like the Joker but for teenage girls. \n
I support women's rights but more important I support women's wrongs.\n
I'm not single. I'm taken. Taking my own life.\n
If they can put one man in the moon... why can't they put all of them there?"

echo $PHRASES | sed "$(shuf -i 1-$(echo $PHRASES | wc -l) -n1)!d"
