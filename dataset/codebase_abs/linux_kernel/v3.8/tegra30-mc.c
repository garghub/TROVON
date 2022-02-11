static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = 0 ;
if ( V_3 < 0x10 )
V_4 = F_2 ( V_2 -> V_5 [ 0 ] + V_3 ) ;
else if ( V_3 < 0x1f0 )
V_4 = F_2 ( V_2 -> V_5 [ 1 ] + V_3 - 0x3c ) ;
else if ( V_3 < 0x228 )
V_4 = F_2 ( V_2 -> V_5 [ 2 ] + V_3 - 0x200 ) ;
else if ( V_3 < 0x400 )
V_4 = F_2 ( V_2 -> V_5 [ 3 ] + V_3 - 0x284 ) ;
return V_4 ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_3 )
{
if ( V_3 < 0x10 )
F_4 ( V_4 , V_2 -> V_5 [ 0 ] + V_3 ) ;
else if ( V_3 < 0x1f0 )
F_4 ( V_4 , V_2 -> V_5 [ 1 ] + V_3 - 0x3c ) ;
else if ( V_3 < 0x228 )
F_4 ( V_4 , V_2 -> V_5 [ 2 ] + V_3 - 0x200 ) ;
else if ( V_3 < 0x400 )
F_4 ( V_4 , V_2 -> V_5 [ 3 ] + V_3 - 0x284 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_6 )
{
T_1 V_7 , V_8 ;
const char * const V_9 [] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
L_5 ,
} ;
const char * const V_10 [] = {
L_2 ,
L_2 ,
L_6 ,
L_7 ,
L_8 ,
L_2 ,
L_9 ,
L_2 ,
} ;
char V_11 [ 6 ] ;
int V_12 , V_13 , type , V_14 ;
const char * V_15 = L_2 ;
V_14 = V_6 - V_16 ;
if ( ( V_14 < 0 ) || ( V_14 >= F_6 ( V_9 ) ) || ( V_14 == 1 ) ) {
F_7 ( V_2 -> V_17 , L_10 ,
F_8 ( V_6 ) ) ;
return;
}
V_7 = F_2 ( V_2 + V_18 ) ;
type = ( V_7 & V_19 ) >> V_20 ;
V_13 = ( V_7 & V_21 ) >>
V_22 ;
if ( type == V_23 )
sprintf ( V_11 , L_11 ,
( V_13 & F_8 ( 2 ) ) ? 'R' : '-' ,
( V_13 & F_8 ( 1 ) ) ? 'W' : '-' ,
( V_13 & F_8 ( 0 ) ) ? 'S' : '-' ) ;
else
V_11 [ 0 ] = '\0' ;
V_12 = V_7 & V_24 ;
if ( V_12 < F_6 ( V_25 ) )
V_15 = V_25 [ V_12 ] ;
V_8 = F_2 ( V_2 + V_26 ) ;
F_7 ( V_2 -> V_17 , L_12 ,
V_9 [ V_14 ] , V_7 , V_8 , V_15 ,
( V_7 & V_27 ) ? L_13 : L_14 ,
( V_7 & V_28 ) ? L_15 : L_16 ,
V_10 [ type ] , V_11 ) ;
}
static int F_9 ( struct V_29 * V_17 )
{
int V_30 ;
struct V_1 * V_2 = F_10 ( V_17 ) ;
for ( V_30 = 0 ; V_30 < F_6 ( V_31 ) ; V_30 ++ )
V_2 -> V_32 [ V_30 ] = F_1 ( V_2 , V_31 [ V_30 ] ) ;
return 0 ;
}
static int F_11 ( struct V_29 * V_17 )
{
int V_30 ;
struct V_1 * V_2 = F_10 ( V_17 ) ;
for ( V_30 = 0 ; V_30 < F_6 ( V_31 ) ; V_30 ++ )
F_3 ( V_2 , V_2 -> V_32 [ V_30 ] , V_31 [ V_30 ] ) ;
F_3 ( V_2 , 1 , V_33 ) ;
F_1 ( V_2 , V_33 ) ;
return 0 ;
}
static T_2 F_12 ( int V_34 , void * V_35 )
{
T_1 V_36 , V_37 , V_38 ;
struct V_1 * V_2 = V_35 ;
V_36 = F_1 ( V_2 , V_39 ) ;
V_37 = F_1 ( V_2 , V_40 ) ;
V_37 &= V_36 ;
if ( ! V_37 )
return V_41 ;
while ( ( V_38 = F_13 ( V_37 ) ) != 0 )
F_5 ( V_2 , V_38 - 1 ) ;
F_3 ( V_2 , V_36 , V_39 ) ;
return V_42 ;
}
static int F_14 ( struct V_43 * V_44 )
{
struct V_45 * V_34 ;
struct V_1 * V_2 ;
T_3 V_46 ;
int V_7 , V_30 ;
T_1 V_47 ;
V_46 = sizeof( * V_2 ) + sizeof( T_1 ) * F_6 ( V_31 ) ;
V_2 = F_15 ( & V_44 -> V_17 , V_46 , V_48 ) ;
if ( ! V_2 )
return - V_49 ;
V_2 -> V_17 = & V_44 -> V_17 ;
for ( V_30 = 0 ; V_30 < F_6 ( V_2 -> V_5 ) ; V_30 ++ ) {
struct V_45 * V_50 ;
V_50 = F_16 ( V_44 , V_51 , V_30 ) ;
if ( ! V_50 )
return - V_52 ;
V_2 -> V_5 [ V_30 ] = F_17 ( & V_44 -> V_17 , V_50 ) ;
if ( ! V_2 -> V_5 [ V_30 ] )
return - V_53 ;
}
V_34 = F_16 ( V_44 , V_54 , 0 ) ;
if ( ! V_34 )
return - V_52 ;
V_7 = F_18 ( & V_44 -> V_17 , V_34 -> V_55 , F_12 ,
V_56 , F_19 ( & V_44 -> V_17 ) , V_2 ) ;
if ( V_7 )
return - V_52 ;
F_20 ( V_44 , V_2 ) ;
V_47 = V_57 |
V_58 | V_59 ;
F_3 ( V_2 , V_47 , V_40 ) ;
return 0 ;
}
