static int
F_1 ( int line , T_1 * V_1 , T_1 * V_2 )
{
const T_2 V_3 [ 4 ] = { 0xe104 , 0xe108 , 0xe280 , 0xe284 } ;
if ( line >= 32 )
return - V_4 ;
* V_1 = V_3 [ line >> 3 ] ;
* V_2 = ( line & 7 ) << 2 ;
return 0 ;
}
int
F_2 ( struct V_5 * V_6 , int line , int V_7 , int V_8 )
{
T_1 V_1 , V_2 ;
if ( F_1 ( line , & V_1 , & V_2 ) )
return - V_4 ;
F_3 ( V_6 , V_1 , 7 << V_2 , ( ( ( V_7 ^ 1 ) << 1 ) | V_8 ) << V_2 ) ;
return 0 ;
}
int
F_4 ( struct V_5 * V_6 , int line )
{
T_1 V_1 , V_2 ;
if ( F_1 ( line , & V_1 , & V_2 ) )
return - V_4 ;
return ! ! ( F_5 ( V_6 , V_1 ) & ( 4 << V_2 ) ) ;
}
void
F_6 ( struct V_5 * V_6 , int line , bool V_9 )
{
T_1 V_1 = line < 16 ? 0xe050 : 0xe070 ;
T_1 V_10 = 0x00010001 << ( line & 0xf ) ;
F_7 ( V_6 , V_1 + 4 , V_10 ) ;
F_3 ( V_6 , V_1 + 0 , V_10 , V_9 ? V_10 : 0 ) ;
}
int
F_8 ( struct V_5 * V_6 , int line , int V_7 , int V_8 )
{
T_1 V_11 = ( ( V_7 ^ 1 ) << 13 ) | ( V_8 << 12 ) ;
F_3 ( V_6 , 0x00d610 + ( line * 4 ) , 0x00003000 , V_11 ) ;
F_3 ( V_6 , 0x00d604 , 0x00000001 , 0x00000001 ) ;
return 0 ;
}
int
F_9 ( struct V_5 * V_6 , int line )
{
return ! ! ( F_5 ( V_6 , 0x00d610 + ( line * 4 ) ) & 0x00004000 ) ;
}
static void
F_10 ( struct V_5 * V_6 )
{
struct V_12 * V_13 = V_6 -> V_14 ;
T_1 V_15 , V_16 = 0 ;
T_1 V_17 , V_18 ;
V_15 = F_5 ( V_6 , 0xe054 ) & F_5 ( V_6 , 0xe050 ) ;
if ( V_13 -> V_19 >= 0x90 )
V_16 = F_5 ( V_6 , 0xe074 ) & F_5 ( V_6 , 0xe070 ) ;
V_17 = ( V_15 & 0x0000ffff ) | ( V_16 << 16 ) ;
V_18 = ( V_15 >> 16 ) | ( V_16 & 0xffff0000 ) ;
F_11 ( V_6 , 0 , V_17 | V_18 ) ;
F_7 ( V_6 , 0xe054 , V_15 ) ;
if ( V_13 -> V_19 >= 0x90 )
F_7 ( V_6 , 0xe074 , V_16 ) ;
}
int
F_12 ( struct V_5 * V_6 )
{
struct V_12 * V_13 = V_6 -> V_14 ;
if ( F_13 ( V_20 ) )
F_14 ( V_6 ) ;
F_7 ( V_6 , 0xe050 , 0x00000000 ) ;
F_7 ( V_6 , 0xe054 , 0xffffffff ) ;
if ( V_13 -> V_19 >= 0x90 ) {
F_7 ( V_6 , 0xe070 , 0x00000000 ) ;
F_7 ( V_6 , 0xe074 , 0xffffffff ) ;
}
F_15 ( V_6 , 21 , F_10 ) ;
return 0 ;
}
void
F_16 ( struct V_5 * V_6 )
{
struct V_12 * V_13 = V_6 -> V_14 ;
F_7 ( V_6 , 0xe050 , 0x00000000 ) ;
if ( V_13 -> V_19 >= 0x90 )
F_7 ( V_6 , 0xe070 , 0x00000000 ) ;
F_17 ( V_6 , 21 ) ;
}
