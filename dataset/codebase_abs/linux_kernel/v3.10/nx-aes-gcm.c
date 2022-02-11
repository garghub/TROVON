static int F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
F_3 ( V_6 , V_11 ) ;
switch ( V_4 ) {
case V_12 :
F_4 ( V_9 , V_13 ) ;
F_4 ( V_10 , V_13 ) ;
V_6 -> V_14 = & V_6 -> V_15 [ V_16 ] ;
break;
case V_17 :
F_4 ( V_9 , V_18 ) ;
F_4 ( V_10 , V_18 ) ;
V_6 -> V_14 = & V_6 -> V_15 [ V_19 ] ;
break;
case V_20 :
F_4 ( V_9 , V_21 ) ;
F_4 ( V_10 , V_21 ) ;
V_6 -> V_14 = & V_6 -> V_15 [ V_22 ] ;
break;
default:
return - V_23 ;
}
V_9 -> V_24 . V_25 . V_26 = V_27 ;
memcpy ( V_9 -> V_24 . V_28 . V_29 , V_3 , V_4 ) ;
V_10 -> V_24 . V_25 . V_26 = V_30 ;
memcpy ( V_10 -> V_24 . V_31 . V_29 , V_3 , V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
char * V_32 = V_6 -> V_33 . V_34 . V_32 ;
int V_35 ;
if ( V_4 < 4 )
return - V_23 ;
V_4 -= 4 ;
V_35 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_35 )
goto V_36;
memcpy ( V_32 , V_3 + V_4 , 4 ) ;
V_36:
return V_35 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_37 )
{
if ( V_37 > F_7 ( V_2 ) -> V_38 )
return - V_23 ;
F_8 ( V_2 ) -> V_37 = V_37 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned int V_37 )
{
switch ( V_37 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_23 ;
}
F_8 ( V_2 ) -> V_37 = V_37 ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 ,
struct V_39 * V_40 ,
T_1 * V_36 )
{
struct V_8 * V_10 = V_6 -> V_10 ;
int V_35 = - V_23 ;
struct V_41 V_42 ;
struct V_43 * V_43 = V_6 -> V_44 ;
if ( V_40 -> V_45 > V_6 -> V_14 -> V_46 )
goto V_36;
if ( V_40 -> V_45 <= V_47 ) {
F_11 ( & V_42 , V_40 -> V_48 ) ;
F_12 ( V_36 , & V_42 , V_40 -> V_45 ,
V_49 ) ;
F_13 ( & V_42 , V_49 , 0 ) ;
V_35 = 0 ;
goto V_36;
}
V_43 = F_14 ( V_43 , V_6 -> V_14 -> V_50 , V_40 -> V_48 , 0 ,
V_40 -> V_45 ) ;
V_6 -> V_51 . V_52 = ( V_6 -> V_44 - V_43 ) * sizeof( struct V_43 ) ;
V_35 = F_15 ( V_6 , & V_6 -> V_51 ,
V_40 -> V_7 . V_53 & V_54 ) ;
if ( V_35 )
goto V_36;
F_16 ( & ( V_6 -> V_55 -> V_56 ) ) ;
F_17 ( V_40 -> V_45 , & ( V_6 -> V_55 -> V_57 ) ) ;
memcpy ( V_36 , V_10 -> V_24 . V_31 . V_58 , V_47 ) ;
V_36:
return V_35 ;
}
static int F_18 ( struct V_39 * V_40 , int V_59 )
{
struct V_5 * V_6 = F_2 ( V_40 -> V_7 . V_2 ) ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_60 V_61 ;
unsigned int V_62 = V_40 -> V_63 ;
int V_35 = - V_23 ;
if ( V_62 > V_6 -> V_14 -> V_46 )
goto V_36;
V_61 . V_64 = V_6 -> V_33 . V_34 . V_65 ;
* ( V_66 * ) ( V_61 . V_64 + V_67 ) = 1 ;
if ( V_62 == 0 ) {
char V_68 [ V_47 ] = {} ;
struct V_69 V_70 ;
V_61 . V_2 = F_19 ( L_1 , 0 , 0 ) ;
if ( F_20 ( V_61 . V_2 ) ) {
V_35 = - V_71 ;
goto V_36;
}
F_21 ( V_61 . V_2 , V_9 -> V_24 . V_28 . V_29 ,
F_22 ( V_9 ) == V_13 ? 16 :
F_22 ( V_9 ) == V_18 ? 24 : 32 ) ;
F_23 ( & V_70 , V_68 , V_47 ) ;
if ( V_59 )
F_24 ( & V_61 , V_40 -> V_72 , & V_70 ,
V_47 ) ;
else
F_25 ( & V_61 , V_40 -> V_72 , & V_70 ,
V_47 ) ;
F_26 ( V_61 . V_2 ) ;
V_35 = 0 ;
goto V_36;
}
V_61 . V_2 = (struct V_73 * ) V_40 -> V_7 . V_2 ;
V_9 -> V_24 . V_28 . V_74 = V_40 -> V_45 * 8 ;
if ( V_40 -> V_45 ) {
V_35 = F_10 ( V_6 , V_40 , V_9 -> V_24 . V_28 . V_75 ) ;
if ( V_35 )
goto V_36;
}
if ( V_59 )
F_27 ( V_9 ) |= V_76 ;
else
V_62 -= F_28 ( F_29 ( V_40 ) ) ;
V_9 -> V_24 . V_28 . V_77 = V_62 * 8 ;
V_35 = F_30 ( V_6 , & V_61 , V_40 -> V_72 , V_40 -> V_68 , V_62 ,
V_9 -> V_24 . V_28 . V_78 ) ;
if ( V_35 )
goto V_36;
V_35 = F_15 ( V_6 , & V_6 -> V_79 ,
V_40 -> V_7 . V_53 & V_54 ) ;
if ( V_35 )
goto V_36;
F_16 ( & ( V_6 -> V_55 -> V_56 ) ) ;
F_17 ( V_9 -> V_80 . V_81 ,
& ( V_6 -> V_55 -> V_57 ) ) ;
if ( V_59 ) {
F_31 ( V_9 -> V_24 . V_28 . V_82 ,
V_40 -> V_72 , V_62 ,
F_28 ( F_29 ( V_40 ) ) ,
V_83 ) ;
} else if ( V_40 -> V_45 ) {
T_1 * V_84 = V_6 -> V_33 . V_34 . V_85 ;
T_1 * V_86 = V_9 -> V_24 . V_28 . V_82 ;
F_31 ( V_84 , V_40 -> V_72 , V_62 ,
F_28 ( F_29 ( V_40 ) ) ,
V_49 ) ;
V_35 = memcmp ( V_84 , V_86 ,
F_28 ( F_29 ( V_40 ) ) ) ?
- V_87 : 0 ;
}
V_36:
return V_35 ;
}
static int F_32 ( struct V_39 * V_40 )
{
struct V_5 * V_6 = F_2 ( V_40 -> V_7 . V_2 ) ;
char * V_65 = V_6 -> V_33 . V_34 . V_65 ;
memcpy ( V_65 , V_40 -> V_65 , 12 ) ;
return F_18 ( V_40 , 1 ) ;
}
static int F_33 ( struct V_39 * V_40 )
{
struct V_5 * V_6 = F_2 ( V_40 -> V_7 . V_2 ) ;
char * V_65 = V_6 -> V_33 . V_34 . V_65 ;
memcpy ( V_65 , V_40 -> V_65 , 12 ) ;
return F_18 ( V_40 , 0 ) ;
}
static int F_34 ( struct V_39 * V_40 )
{
struct V_5 * V_6 = F_2 ( V_40 -> V_7 . V_2 ) ;
char * V_65 = V_6 -> V_33 . V_34 . V_65 ;
char * V_32 = V_6 -> V_33 . V_34 . V_32 ;
memcpy ( V_65 , V_32 , V_88 ) ;
memcpy ( V_65 + V_88 , V_40 -> V_65 , 8 ) ;
return F_18 ( V_40 , 1 ) ;
}
static int F_35 ( struct V_39 * V_40 )
{
struct V_5 * V_6 = F_2 ( V_40 -> V_7 . V_2 ) ;
char * V_65 = V_6 -> V_33 . V_34 . V_65 ;
char * V_32 = V_6 -> V_33 . V_34 . V_32 ;
memcpy ( V_65 , V_32 , V_88 ) ;
memcpy ( V_65 + V_88 , V_40 -> V_65 , 8 ) ;
return F_18 ( V_40 , 0 ) ;
}
