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
T_2 V_24 = 0 ;
int V_25 ;
V_25 = F_10 ( V_5 -> V_26 , & V_5 -> V_18 ) ;
if ( V_25 )
goto V_27;
if ( V_2 -> V_28 ) {
V_24 = F_11 () ;
memcpy ( ( V_29 * ) V_5 -> V_19 + V_2 -> V_30 - sizeof( T_2 ) ,
& V_24 , sizeof( V_24 ) ) ;
}
F_12 ( V_2 , ( V_29 * ) V_5 -> V_19 ) ;
V_27:
F_13 ( V_2 -> V_31 ) ;
return V_32 ;
}
static int F_14 ( struct V_4 * V_5 , unsigned V_33 )
{
int V_34 ;
V_5 -> V_14 [ 0 ] = F_6 ( V_11 | V_5 -> V_12 |
( F_4 ( 0 ) >> V_33 ) ) ;
V_34 = F_10 ( V_5 -> V_26 , & V_5 -> V_35 ) ;
if ( V_34 )
return V_34 ;
return F_15 ( V_5 -> V_19 [ 0 ] ) ;
}
static int F_16 ( struct V_4 * V_5 , int * V_36 )
{
int V_34 ;
T_3 V_37 ;
V_37 = F_6 ( V_11 | V_38 |
V_39 | V_5 -> V_12 ) ;
V_34 = F_17 ( V_5 -> V_26 , ( V_29 * ) & V_37 , 2 ) ;
if ( V_34 )
return V_34 ;
V_37 = F_6 ( 0 ) ;
V_34 = F_17 ( V_5 -> V_26 , ( V_29 * ) & V_37 , 2 ) ;
if ( V_34 )
return V_34 ;
F_18 ( 101 , 1000 ) ;
V_34 = F_19 ( V_5 -> V_26 , ( V_29 * ) & V_37 , 2 ) ;
if ( V_34 )
return V_34 ;
* V_36 = F_20 ( F_15 ( V_37 ) , 11 ) ;
return 0 ;
}
static int F_21 ( struct V_4 * V_5 )
{
int V_40 ;
if ( V_5 -> V_12 ) {
V_40 = F_22 ( V_5 -> V_41 ) ;
if ( V_40 < 0 )
return V_40 ;
return V_40 / 1000 ;
} else {
return V_42 ;
}
}
static int F_23 ( struct V_1 * V_2 ,
struct V_43 const * V_44 ,
int * V_36 ,
int * V_45 ,
long V_7 )
{
int V_34 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_7 ) {
case V_46 :
F_24 ( & V_2 -> V_47 ) ;
if ( V_2 -> V_48 == V_49 ) {
V_34 = - V_50 ;
} else {
if ( V_44 -> V_51 == V_52 )
V_34 = F_16 ( V_5 , V_36 ) ;
else
V_34 = F_14 ( V_5 , V_44 -> V_51 ) ;
}
F_25 ( & V_2 -> V_47 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_44 -> V_51 != V_52 )
* V_36 = V_34 & F_26 ( V_53 ) ;
return V_54 ;
case V_55 :
switch ( V_44 -> type ) {
case V_56 :
* V_36 = F_21 ( V_5 ) ;
* V_45 = V_44 -> V_57 . V_58 ;
return V_59 ;
case V_60 :
* V_36 = F_21 ( V_5 ) ;
* V_45 = 10 ;
return V_61 ;
default:
return - V_62 ;
}
case V_63 :
* V_36 = 1093 - 2732500 / F_21 ( V_5 ) ;
return V_54 ;
}
return - V_62 ;
}
static int F_27 ( struct V_64 * V_26 )
{
struct V_65 * V_66 = V_26 -> V_67 . V_68 ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
int V_34 ;
V_2 = F_28 ( & V_26 -> V_67 , sizeof( * V_5 ) ) ;
if ( V_2 == NULL )
return - V_69 ;
V_5 = F_2 ( V_2 ) ;
if ( V_66 && V_66 -> V_12 )
V_5 -> V_12 = V_70 ;
if ( V_5 -> V_12 ) {
V_5 -> V_41 = F_29 ( & V_26 -> V_67 , L_1 ) ;
if ( F_30 ( V_5 -> V_41 ) )
return F_31 ( V_5 -> V_41 ) ;
V_34 = F_32 ( V_5 -> V_41 ) ;
if ( V_34 )
return V_34 ;
}
F_33 ( V_26 , V_2 ) ;
V_5 -> V_26 = V_26 ;
V_2 -> V_71 = F_34 ( V_26 ) -> V_71 ;
V_2 -> V_67 . V_72 = & V_26 -> V_67 ;
V_2 -> V_73 = V_74 ;
V_2 -> V_75 = V_76 ;
V_2 -> V_77 = F_35 ( V_76 ) ;
V_2 -> V_78 = & V_79 ;
V_5 -> V_80 [ 0 ] . V_14 = & V_5 -> V_14 [ 0 ] ;
V_5 -> V_80 [ 0 ] . V_16 = 2 ;
V_5 -> V_80 [ 0 ] . V_17 = 1 ;
V_5 -> V_80 [ 1 ] . V_14 = & V_5 -> V_14 [ 1 ] ;
V_5 -> V_80 [ 1 ] . V_16 = 2 ;
V_5 -> V_80 [ 1 ] . V_17 = 1 ;
V_5 -> V_80 [ 2 ] . V_19 = & V_5 -> V_19 [ 0 ] ;
V_5 -> V_80 [ 2 ] . V_16 = 2 ;
F_7 ( & V_5 -> V_35 ) ;
F_8 ( & V_5 -> V_80 [ 0 ] , & V_5 -> V_35 ) ;
F_8 ( & V_5 -> V_80 [ 1 ] , & V_5 -> V_35 ) ;
F_8 ( & V_5 -> V_80 [ 2 ] , & V_5 -> V_35 ) ;
V_34 = F_36 ( V_2 , NULL ,
& F_9 , NULL ) ;
if ( V_34 )
goto V_81;
V_34 = F_37 ( V_2 ) ;
if ( V_34 )
goto V_82;
return 0 ;
V_82:
F_38 ( V_2 ) ;
V_81:
if ( V_5 -> V_12 )
F_39 ( V_5 -> V_41 ) ;
return V_34 ;
}
static int F_40 ( struct V_64 * V_26 )
{
struct V_1 * V_2 = F_41 ( V_26 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_42 ( V_2 ) ;
F_38 ( V_2 ) ;
if ( V_5 -> V_12 )
F_39 ( V_5 -> V_41 ) ;
return 0 ;
}
