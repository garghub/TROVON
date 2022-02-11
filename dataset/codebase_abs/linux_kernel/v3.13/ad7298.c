static int F_1 ( struct V_1 * V_2 ,
const unsigned long * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 ;
unsigned short V_8 ;
int V_9 ;
V_9 = F_3 ( V_3 , V_2 -> V_10 ) ;
V_8 = V_11 | V_5 -> V_12 ;
for ( V_6 = 0 , V_7 = F_4 ( 0 ) ; V_6 < V_13 ; V_6 ++ , V_7 >>= 1 )
if ( F_5 ( V_6 , V_3 ) )
V_8 |= V_7 ;
V_5 -> V_14 [ 0 ] = F_6 ( V_8 ) ;
V_5 -> V_15 [ 0 ] . V_14 = & V_5 -> V_14 [ 0 ] ;
V_5 -> V_15 [ 0 ] . V_16 = 2 ;
V_5 -> V_15 [ 0 ] . V_17 = 1 ;
V_5 -> V_15 [ 1 ] . V_14 = & V_5 -> V_14 [ 1 ] ;
V_5 -> V_15 [ 1 ] . V_16 = 2 ;
V_5 -> V_15 [ 1 ] . V_17 = 1 ;
F_7 ( & V_5 -> V_18 ) ;
F_8 ( & V_5 -> V_15 [ 0 ] , & V_5 -> V_18 ) ;
F_8 ( & V_5 -> V_15 [ 1 ] , & V_5 -> V_18 ) ;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
V_5 -> V_15 [ V_6 + 2 ] . V_19 = & V_5 -> V_19 [ V_6 ] ;
V_5 -> V_15 [ V_6 + 2 ] . V_16 = 2 ;
V_5 -> V_15 [ V_6 + 2 ] . V_17 = 1 ;
F_8 ( & V_5 -> V_15 [ V_6 + 2 ] , & V_5 -> V_18 ) ;
}
V_5 -> V_15 [ V_6 + 1 ] . V_17 = 0 ;
return 0 ;
}
static T_1 F_9 ( int V_20 , void * V_21 )
{
struct V_22 * V_23 = V_21 ;
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_24 ;
V_24 = F_10 ( V_5 -> V_25 , & V_5 -> V_18 ) ;
if ( V_24 )
goto V_26;
F_11 ( V_2 , V_5 -> V_19 ,
F_12 () ) ;
V_26:
F_13 ( V_2 -> V_27 ) ;
return V_28 ;
}
static int F_14 ( struct V_4 * V_5 , unsigned V_29 )
{
int V_30 ;
V_5 -> V_14 [ 0 ] = F_6 ( V_11 | V_5 -> V_12 |
( F_4 ( 0 ) >> V_29 ) ) ;
V_30 = F_10 ( V_5 -> V_25 , & V_5 -> V_31 ) ;
if ( V_30 )
return V_30 ;
return F_15 ( V_5 -> V_19 [ 0 ] ) ;
}
static int F_16 ( struct V_4 * V_5 , int * V_32 )
{
int V_30 ;
T_2 V_33 ;
V_33 = F_6 ( V_11 | V_34 |
V_35 | V_5 -> V_12 ) ;
V_30 = F_17 ( V_5 -> V_25 , ( V_36 * ) & V_33 , 2 ) ;
if ( V_30 )
return V_30 ;
V_33 = F_6 ( 0 ) ;
V_30 = F_17 ( V_5 -> V_25 , ( V_36 * ) & V_33 , 2 ) ;
if ( V_30 )
return V_30 ;
F_18 ( 101 , 1000 ) ;
V_30 = F_19 ( V_5 -> V_25 , ( V_36 * ) & V_33 , 2 ) ;
if ( V_30 )
return V_30 ;
* V_32 = F_20 ( F_15 ( V_33 ) , 11 ) ;
return 0 ;
}
static int F_21 ( struct V_4 * V_5 )
{
int V_37 ;
if ( V_5 -> V_12 ) {
V_37 = F_22 ( V_5 -> V_38 ) ;
if ( V_37 < 0 )
return V_37 ;
return V_37 / 1000 ;
} else {
return V_39 ;
}
}
static int F_23 ( struct V_1 * V_2 ,
struct V_40 const * V_41 ,
int * V_32 ,
int * V_42 ,
long V_7 )
{
int V_30 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_7 ) {
case V_43 :
F_24 ( & V_2 -> V_44 ) ;
if ( V_2 -> V_45 == V_46 ) {
V_30 = - V_47 ;
} else {
if ( V_41 -> V_48 == V_49 )
V_30 = F_16 ( V_5 , V_32 ) ;
else
V_30 = F_14 ( V_5 , V_41 -> V_48 ) ;
}
F_25 ( & V_2 -> V_44 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_41 -> V_48 != V_49 )
* V_32 = V_30 & F_26 ( V_50 ) ;
return V_51 ;
case V_52 :
switch ( V_41 -> type ) {
case V_53 :
* V_32 = F_21 ( V_5 ) ;
* V_42 = V_41 -> V_54 . V_55 ;
return V_56 ;
case V_57 :
* V_32 = F_21 ( V_5 ) ;
* V_42 = 10 ;
return V_58 ;
default:
return - V_59 ;
}
case V_60 :
* V_32 = 1093 - 2732500 / F_21 ( V_5 ) ;
return V_51 ;
}
return - V_59 ;
}
static int F_27 ( struct V_61 * V_25 )
{
struct V_62 * V_63 = V_25 -> V_64 . V_65 ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
int V_30 ;
V_2 = F_28 ( & V_25 -> V_64 , sizeof( * V_5 ) ) ;
if ( V_2 == NULL )
return - V_66 ;
V_5 = F_2 ( V_2 ) ;
if ( V_63 && V_63 -> V_12 )
V_5 -> V_12 = V_67 ;
if ( V_5 -> V_12 ) {
V_5 -> V_38 = F_29 ( & V_25 -> V_64 , L_1 ) ;
if ( F_30 ( V_5 -> V_38 ) )
return F_31 ( V_5 -> V_38 ) ;
V_30 = F_32 ( V_5 -> V_38 ) ;
if ( V_30 )
return V_30 ;
}
F_33 ( V_25 , V_2 ) ;
V_5 -> V_25 = V_25 ;
V_2 -> V_68 = F_34 ( V_25 ) -> V_68 ;
V_2 -> V_64 . V_69 = & V_25 -> V_64 ;
V_2 -> V_70 = V_71 ;
V_2 -> V_72 = V_73 ;
V_2 -> V_74 = F_35 ( V_73 ) ;
V_2 -> V_75 = & V_76 ;
V_5 -> V_77 [ 0 ] . V_14 = & V_5 -> V_14 [ 0 ] ;
V_5 -> V_77 [ 0 ] . V_16 = 2 ;
V_5 -> V_77 [ 0 ] . V_17 = 1 ;
V_5 -> V_77 [ 1 ] . V_14 = & V_5 -> V_14 [ 1 ] ;
V_5 -> V_77 [ 1 ] . V_16 = 2 ;
V_5 -> V_77 [ 1 ] . V_17 = 1 ;
V_5 -> V_77 [ 2 ] . V_19 = & V_5 -> V_19 [ 0 ] ;
V_5 -> V_77 [ 2 ] . V_16 = 2 ;
F_7 ( & V_5 -> V_31 ) ;
F_8 ( & V_5 -> V_77 [ 0 ] , & V_5 -> V_31 ) ;
F_8 ( & V_5 -> V_77 [ 1 ] , & V_5 -> V_31 ) ;
F_8 ( & V_5 -> V_77 [ 2 ] , & V_5 -> V_31 ) ;
V_30 = F_36 ( V_2 , NULL ,
& F_9 , NULL ) ;
if ( V_30 )
goto V_78;
V_30 = F_37 ( V_2 ) ;
if ( V_30 )
goto V_79;
return 0 ;
V_79:
F_38 ( V_2 ) ;
V_78:
if ( V_5 -> V_12 )
F_39 ( V_5 -> V_38 ) ;
return V_30 ;
}
static int F_40 ( struct V_61 * V_25 )
{
struct V_1 * V_2 = F_41 ( V_25 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_42 ( V_2 ) ;
F_38 ( V_2 ) ;
if ( V_5 -> V_12 )
F_39 ( V_5 -> V_38 ) ;
return 0 ;
}
