void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , enum V_5 V_6 ,
T_1 V_7 )
{
struct V_8 * V_8 = V_2 -> V_9 ;
if ( V_3 == 0xffe ) {
F_2 ( 50 ) ;
} else if ( V_3 == 0xfd ) {
F_3 ( 5 ) ;
} else if ( V_3 == 0xfc ) {
F_3 ( 1 ) ;
} else if ( V_3 == 0xfb ) {
F_4 ( 50 ) ;
} else if ( V_3 == 0xfa ) {
F_4 ( 5 ) ;
} else if ( V_3 == 0xf9 ) {
F_4 ( 1 ) ;
} else {
F_5 ( V_8 , V_6 , V_7 , V_10 , V_4 ) ;
F_4 ( 1 ) ;
}
}
void F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_11 = 0x1000 ;
T_1 V_12 = ( T_1 ) ( V_11 & 0xE000 ) ;
F_1 ( V_2 , V_3 , V_4 , V_13 , V_3 | V_12 ) ;
F_7 ( V_2 , V_14 , V_15 , ( L_1 , V_3 , V_4 ) ) ;
}
void F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_11 = 0x1001 ;
T_1 V_12 = ( T_1 ) ( V_11 & 0xE000 ) ;
F_1 ( V_2 , V_3 , V_4 , V_16 , V_3 | V_12 ) ;
F_7 ( V_2 , V_14 , V_15 , ( L_2 , V_3 , V_4 ) ) ;
}
void F_9 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
F_10 ( V_2 , V_3 , V_4 ) ;
F_7 ( V_2 , V_14 , V_15 , ( L_3 , V_3 , V_4 ) ) ;
}
void F_11 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_17 , T_1 V_4 )
{
struct V_8 * V_8 = V_2 -> V_9 ;
F_12 ( V_8 , V_3 , V_17 , V_4 ) ;
F_4 ( 1 ) ;
F_7 ( V_2 , V_14 , V_15 ,
( L_4 ,
V_3 , V_4 ) ) ;
}
void F_13 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_17 , T_1 V_4 )
{
if ( V_3 == 0xfe ) {
F_2 ( 50 ) ;
} else if ( V_3 == 0xfd ) {
F_3 ( 5 ) ;
} else if ( V_3 == 0xfc ) {
F_3 ( 1 ) ;
} else if ( V_3 == 0xfb ) {
F_4 ( 50 ) ;
} else if ( V_3 == 0xfa ) {
F_4 ( 5 ) ;
} else if ( V_3 == 0xf9 ) {
F_4 ( 1 ) ;
} else{
F_7 ( V_2 , V_14 , V_18 ,
( L_5 ,
V_3 , V_17 , V_4 ) ) ;
F_14 ( V_2 -> V_9 , V_3 , V_17 , V_4 ) ;
}
}
void F_15 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_17 , T_1 V_4 )
{
struct V_8 * V_8 = V_2 -> V_9 ;
if ( V_3 == 0xfe ) {
F_2 ( 50 ) ;
} else if ( V_3 == 0xfd ) {
F_3 ( 5 ) ;
} else if ( V_3 == 0xfc ) {
F_3 ( 1 ) ;
} else if ( V_3 == 0xfb ) {
F_4 ( 50 ) ;
} else if ( V_3 == 0xfa ) {
F_4 ( 5 ) ;
} else if ( V_3 == 0xf9 ) {
F_4 ( 1 ) ;
} else {
if ( V_3 == 0xa24 )
V_2 -> V_19 . V_20 = V_4 ;
F_12 ( V_8 , V_3 , V_17 , V_4 ) ;
F_4 ( 1 ) ;
F_7 ( V_2 , V_14 , V_15 ,
( L_6 ,
V_3 , V_4 ) ) ;
}
}
