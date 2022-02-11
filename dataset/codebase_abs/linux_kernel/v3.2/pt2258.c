int F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 [ 2 ] ;
int V_4 ;
V_3 [ 0 ] = V_5 ;
F_2 ( V_2 -> V_6 ) ;
if ( F_3 ( V_2 -> V_7 , V_3 , 1 ) != 1 )
goto V_8;
F_4 ( V_2 -> V_6 ) ;
V_2 -> V_9 = 1 ;
V_3 [ 0 ] = V_10 ;
F_2 ( V_2 -> V_6 ) ;
if ( F_3 ( V_2 -> V_7 , V_3 , 1 ) != 1 )
goto V_8;
F_4 ( V_2 -> V_6 ) ;
for ( V_4 = 0 ; V_4 < 6 ; ++ V_4 )
V_2 -> V_11 [ V_4 ] = 0 ;
V_3 [ 0 ] = 0xd0 ;
V_3 [ 1 ] = 0xe0 ;
F_2 ( V_2 -> V_6 ) ;
if ( F_3 ( V_2 -> V_7 , V_3 , 2 ) != 2 )
goto V_8;
F_4 ( V_2 -> V_6 ) ;
return 0 ;
V_8:
F_4 ( V_2 -> V_6 ) ;
F_5 ( V_12 L_1 ) ;
return - V_13 ;
}
static int F_6 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
V_17 -> type = V_18 ;
V_17 -> V_19 = 2 ;
V_17 -> V_20 . integer . V_21 = 0 ;
V_17 -> V_20 . integer . V_22 = 79 ;
return 0 ;
}
static int F_7 ( struct V_14 * V_15 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_15 -> V_25 ;
int V_26 = V_15 -> V_27 ;
V_24 -> V_20 . integer . V_20 [ 0 ] = 79 - V_2 -> V_11 [ V_26 ] ;
V_24 -> V_20 . integer . V_20 [ 1 ] = 79 - V_2 -> V_11 [ V_26 + 1 ] ;
return 0 ;
}
static int F_8 ( struct V_14 * V_15 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_15 -> V_25 ;
int V_26 = V_15 -> V_27 ;
unsigned char V_3 [ 2 ] ;
int V_28 , V_29 ;
V_28 = 79 - V_24 -> V_20 . integer . V_20 [ 0 ] ;
V_29 = 79 - V_24 -> V_20 . integer . V_20 [ 1 ] ;
if ( V_28 < 0 || V_28 > 79 || V_29 < 0 || V_29 > 79 )
return - V_30 ;
if ( V_28 == V_2 -> V_11 [ V_26 ] && V_29 == V_2 -> V_11 [ V_26 + 1 ] )
return 0 ;
V_2 -> V_11 [ V_26 ] = V_28 ;
V_3 [ 0 ] = V_31 [ 2 * V_26 ] | ( V_28 / 10 ) ;
V_3 [ 1 ] = V_31 [ 2 * V_26 + 1 ] | ( V_28 % 10 ) ;
F_2 ( V_2 -> V_6 ) ;
if ( F_3 ( V_2 -> V_7 , V_3 , 2 ) != 2 )
goto V_8;
F_4 ( V_2 -> V_6 ) ;
V_2 -> V_11 [ V_26 + 1 ] = V_29 ;
V_3 [ 0 ] = V_31 [ 2 * V_26 + 2 ] | ( V_29 / 10 ) ;
V_3 [ 1 ] = V_31 [ 2 * V_26 + 3 ] | ( V_29 % 10 ) ;
F_2 ( V_2 -> V_6 ) ;
if ( F_3 ( V_2 -> V_7 , V_3 , 2 ) != 2 )
goto V_8;
F_4 ( V_2 -> V_6 ) ;
return 1 ;
V_8:
F_4 ( V_2 -> V_6 ) ;
F_5 ( V_12 L_2 ) ;
return - V_13 ;
}
static int F_9 ( struct V_14 * V_15 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_15 -> V_25 ;
V_24 -> V_20 . integer . V_20 [ 0 ] = ! V_2 -> V_9 ;
return 0 ;
}
static int F_10 ( struct V_14 * V_15 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_15 -> V_25 ;
unsigned char V_3 [ 2 ] ;
int V_32 ;
V_32 = ! V_24 -> V_20 . integer . V_20 [ 0 ] ;
if ( V_2 -> V_9 == V_32 )
return 0 ;
V_2 -> V_9 = V_32 ;
V_3 [ 0 ] = V_32 ? V_10 : V_33 ;
F_2 ( V_2 -> V_6 ) ;
if ( F_3 ( V_2 -> V_7 , V_3 , 1 ) != 1 )
goto V_8;
F_4 ( V_2 -> V_6 ) ;
return 1 ;
V_8:
F_4 ( V_2 -> V_6 ) ;
F_5 ( V_12 L_3 ) ;
return - V_13 ;
}
int F_11 ( struct V_1 * V_2 )
{
struct V_34 V_35 ;
char * V_36 [ 3 ] = {
L_4 ,
L_5 ,
L_6
} ;
int V_4 , V_37 ;
for ( V_4 = 0 ; V_4 < 3 ; ++ V_4 ) {
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_38 = V_36 [ V_4 ] ;
V_35 . V_39 = V_40 ;
V_35 . V_19 = 1 ;
V_35 . V_41 = V_42 |
V_43 ;
V_35 . V_27 = 2 * V_4 ;
V_35 . V_44 = F_6 ;
V_35 . V_45 = F_7 ;
V_35 . V_46 = F_8 ;
V_35 . V_47 . V_48 = V_49 ;
V_37 = F_12 ( V_2 -> V_50 , F_13 ( & V_35 , V_2 ) ) ;
if ( V_37 < 0 )
return V_37 ;
}
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_38 = L_7 ;
V_35 . V_39 = V_40 ;
V_35 . V_44 = V_51 ;
V_35 . V_45 = F_9 ;
V_35 . V_46 = F_10 ;
V_35 . V_41 = 0 ;
V_37 = F_12 ( V_2 -> V_50 , F_13 ( & V_35 , V_2 ) ) ;
if ( V_37 < 0 )
return V_37 ;
return 0 ;
}
