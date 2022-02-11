static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
if ( V_5 == V_6 ) {
F_2 ( & V_7 . V_8 ,
V_9 , 1 ) ;
F_2 ( & V_7 . V_8 ,
V_10 , 1 ) ;
F_3 ( V_4 , L_1 ) ;
} else {
F_2 ( & V_7 . V_8 ,
V_9 , 0 ) ;
F_2 ( & V_7 . V_8 ,
V_10 , 0 ) ;
F_4 ( V_4 , L_1 ) ;
}
if ( V_11 == V_12 )
F_3 ( V_4 , L_2 ) ;
else
F_4 ( V_4 , L_2 ) ;
F_5 ( V_4 ) ;
}
static int F_6 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
struct V_1 * V_2 = V_16 -> V_2 ;
F_7 ( & V_2 -> V_18 ) ;
F_1 ( V_2 ) ;
F_8 ( & V_2 -> V_18 ) ;
return 0 ;
}
static void F_9 ( struct V_13 * V_14 )
{
F_2 ( & V_7 . V_8 ,
V_9 , 1 ) ;
F_2 ( & V_7 . V_8 ,
V_10 , 1 ) ;
}
static int F_10 ( struct V_13 * V_14 ,
struct V_19 * V_20 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
struct V_21 * V_22 = V_16 -> V_22 ;
struct V_21 * V_23 = V_16 -> V_23 ;
unsigned int V_24 = 0 ;
int V_25 = 0 ;
switch ( F_11 ( V_20 ) ) {
case 8000 :
case 16000 :
case 48000 :
case 96000 :
V_24 = 12288000 ;
break;
case 11025 :
case 22050 :
case 44100 :
V_24 = 11289600 ;
break;
}
V_25 = F_12 ( V_22 , V_26 |
V_27 | V_28 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_12 ( V_23 , V_26 |
V_27 | V_28 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_13 ( V_22 , V_29 , V_24 ,
V_30 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_13 ( V_23 , V_31 , 0 ,
V_30 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static int F_14 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
V_35 -> V_36 . integer . V_36 [ 0 ] = V_5 ;
return 0 ;
}
static int F_15 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = F_16 ( V_33 ) ;
if ( V_5 == V_35 -> V_36 . integer . V_36 [ 0 ] )
return 0 ;
V_5 = V_35 -> V_36 . integer . V_36 [ 0 ] ;
F_1 ( V_2 ) ;
return 1 ;
}
static int F_17 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
V_35 -> V_36 . integer . V_36 [ 0 ] = V_11 ;
return 0 ;
}
static int F_18 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = F_16 ( V_33 ) ;
if ( V_11 == V_35 -> V_36 . integer . V_36 [ 0 ] )
return 0 ;
V_11 = V_35 -> V_36 . integer . V_36 [ 0 ] ;
F_1 ( V_2 ) ;
return 1 ;
}
static int F_19 ( struct V_37 * V_38 ,
struct V_32 * V_39 , int V_40 )
{
if ( F_20 ( V_40 ) )
F_2 ( & V_7 . V_8 ,
V_41 , 0 ) ;
else
F_2 ( & V_7 . V_8 ,
V_41 , 1 ) ;
return 0 ;
}
static int F_21 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_42 ;
F_22 ( V_4 , L_3 ) ;
F_22 ( V_4 , L_4 ) ;
F_3 ( V_4 , L_5 ) ;
V_42 = F_23 ( V_2 , V_43 ,
F_24 ( V_43 ) ) ;
if ( V_42 < 0 )
return V_42 ;
F_25 ( V_4 , V_44 ,
F_24 ( V_44 ) ) ;
F_26 ( V_4 , V_45 , F_24 ( V_45 ) ) ;
return 0 ;
}
static int T_1 F_27 ( void )
{
int V_25 ;
if ( ! F_28 () )
return - V_46 ;
F_29 ( & V_7 . V_8 ,
V_41 , 0 ) ;
F_29 ( & V_7 . V_8 ,
V_9 , 0 ) ;
F_29 ( & V_7 . V_8 ,
V_10 , 0 ) ;
V_47 = F_30 ( L_6 , - 1 ) ;
if ( ! V_47 )
return - V_48 ;
F_31 ( V_47 , & V_49 ) ;
V_25 = F_32 ( V_47 ) ;
if ( V_25 )
F_33 ( V_47 ) ;
return V_25 ;
}
static void T_2 F_34 ( void )
{
F_35 ( V_47 ) ;
}
