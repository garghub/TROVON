static inline int F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 & V_3 ;
}
T_1 F_2 ( struct V_1 * V_1 , T_1 V_4 , T_1 V_5 )
{
if ( V_4 < 0 && ! F_1 ( V_1 ) )
return - V_6 ;
if ( V_4 > V_5 )
return - V_6 ;
if ( V_4 != V_1 -> V_7 ) {
V_1 -> V_7 = V_4 ;
V_1 -> V_8 = 0 ;
}
return V_4 ;
}
T_1
F_3 ( struct V_1 * V_1 , T_1 V_4 , int V_9 ,
T_1 V_5 , T_1 V_10 )
{
switch ( V_9 ) {
case V_11 :
V_4 += V_10 ;
break;
case V_12 :
if ( V_4 == 0 )
return V_1 -> V_7 ;
F_4 ( & V_1 -> V_13 ) ;
V_4 = F_2 ( V_1 , V_1 -> V_7 + V_4 , V_5 ) ;
F_5 ( & V_1 -> V_13 ) ;
return V_4 ;
case V_14 :
if ( V_4 >= V_10 )
return - V_15 ;
break;
case V_16 :
if ( V_4 >= V_10 )
return - V_15 ;
V_4 = V_10 ;
break;
}
return F_2 ( V_1 , V_4 , V_5 ) ;
}
T_1 F_6 ( struct V_1 * V_1 , T_1 V_4 , int V_9 )
{
struct V_17 * V_17 = V_1 -> V_18 -> V_19 ;
return F_3 ( V_1 , V_4 , V_9 ,
V_17 -> V_20 -> V_21 ,
F_7 ( V_17 ) ) ;
}
T_1 F_8 ( struct V_1 * V_1 , T_1 V_4 , int V_9 , T_1 V_22 )
{
switch ( V_9 ) {
case V_23 : case V_12 : case V_11 :
return F_3 ( V_1 , V_4 , V_9 ,
V_22 , V_22 ) ;
default:
return - V_6 ;
}
}
T_1 F_9 ( struct V_1 * V_1 , T_1 V_4 , int V_9 )
{
switch ( V_9 ) {
case V_23 : case V_12 :
return F_3 ( V_1 , V_4 , V_9 ,
V_24 , 0 ) ;
default:
return - V_6 ;
}
}
T_1 F_10 ( struct V_1 * V_1 , T_1 V_4 , int V_9 , T_1 V_22 )
{
switch ( V_9 ) {
case V_23 : case V_12 :
return F_3 ( V_1 , V_4 , V_9 ,
V_22 , 0 ) ;
default:
return - V_6 ;
}
}
T_1 F_11 ( struct V_1 * V_1 , T_1 V_4 , int V_9 )
{
return V_1 -> V_7 ;
}
T_1 F_12 ( struct V_1 * V_1 , T_1 V_4 , int V_9 )
{
return - V_25 ;
}
T_1 F_13 ( struct V_1 * V_1 , T_1 V_4 , int V_9 )
{
struct V_17 * V_17 = F_14 ( V_1 ) ;
T_1 V_26 ;
F_15 ( V_17 ) ;
switch ( V_9 ) {
case V_11 :
V_4 += F_7 ( V_17 ) ;
break;
case V_12 :
if ( V_4 == 0 ) {
V_26 = V_1 -> V_7 ;
goto V_27;
}
V_4 += V_1 -> V_7 ;
break;
case V_14 :
if ( V_4 >= V_17 -> V_28 ) {
V_26 = - V_15 ;
goto V_27;
}
break;
case V_16 :
if ( V_4 >= V_17 -> V_28 ) {
V_26 = - V_15 ;
goto V_27;
}
V_4 = V_17 -> V_28 ;
break;
}
V_26 = - V_6 ;
if ( V_4 >= 0 || F_1 ( V_1 ) ) {
if ( V_4 != V_1 -> V_7 ) {
V_1 -> V_7 = V_4 ;
V_1 -> V_8 = 0 ;
}
V_26 = V_4 ;
}
V_27:
F_16 ( V_17 ) ;
return V_26 ;
}
T_1 F_17 ( struct V_1 * V_1 , T_1 V_4 , int V_9 )
{
T_1 (* F_18)( struct V_1 * , T_1 , int );
F_18 = F_12 ;
if ( V_1 -> V_2 & V_29 ) {
if ( V_1 -> V_30 -> V_31 )
F_18 = V_1 -> V_30 -> V_31 ;
}
return F_18 ( V_1 , V_4 , V_9 ) ;
}
T_2 F_19 ( struct V_1 * V_1 , struct V_32 * V_33 , T_1 * V_34 )
{
struct V_35 V_35 ;
T_2 V_36 ;
if ( ! V_1 -> V_30 -> V_37 )
return - V_6 ;
F_20 ( & V_35 , V_1 ) ;
V_35 . V_38 = * V_34 ;
V_33 -> type |= V_39 ;
V_36 = F_21 ( V_1 , & V_35 , V_33 ) ;
F_22 ( V_36 == - V_40 ) ;
if ( V_36 > 0 )
* V_34 = V_35 . V_38 ;
return V_36 ;
}
T_2 F_23 ( struct V_1 * V_1 , struct V_32 * V_33 , T_1 * V_34 )
{
struct V_35 V_35 ;
T_2 V_36 ;
if ( ! V_1 -> V_30 -> V_41 )
return - V_6 ;
F_20 ( & V_35 , V_1 ) ;
V_35 . V_38 = * V_34 ;
V_33 -> type |= V_42 ;
V_36 = F_24 ( V_1 , & V_35 , V_33 ) ;
F_22 ( V_36 == - V_40 ) ;
if ( V_36 > 0 )
* V_34 = V_35 . V_38 ;
return V_36 ;
}
int F_25 ( int V_43 , struct V_1 * V_1 , const T_1 * V_34 , T_3 V_44 )
{
struct V_17 * V_17 ;
T_1 V_45 ;
int V_26 = - V_6 ;
V_17 = F_14 ( V_1 ) ;
if ( F_26 ( ( T_2 ) V_44 < 0 ) )
return V_26 ;
V_45 = * V_34 ;
if ( F_26 ( V_45 < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_26 ;
if ( V_44 >= - V_45 )
return - V_46 ;
} else if ( F_26 ( ( T_1 ) ( V_45 + V_44 ) < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_26 ;
}
if ( F_26 ( V_17 -> V_47 && F_27 ( V_17 ) ) ) {
V_26 = F_28 ( V_17 , V_1 , V_45 , V_45 + V_44 - 1 ,
V_43 == V_39 ? V_48 : V_49 ) ;
if ( V_26 < 0 )
return V_26 ;
}
return F_29 ( V_1 ,
V_43 == V_39 ? V_50 : V_51 ) ;
}
static T_2 F_30 ( struct V_1 * V_52 , char T_4 * V_53 , T_3 V_54 , T_1 * V_34 )
{
struct V_55 V_56 = { . V_57 = V_53 , . V_58 = V_54 } ;
struct V_35 V_35 ;
struct V_32 V_33 ;
T_2 V_36 ;
F_20 ( & V_35 , V_52 ) ;
V_35 . V_38 = * V_34 ;
F_31 ( & V_33 , V_39 , & V_56 , 1 , V_54 ) ;
V_36 = F_21 ( V_52 , & V_35 , & V_33 ) ;
F_22 ( V_36 == - V_40 ) ;
* V_34 = V_35 . V_38 ;
return V_36 ;
}
T_2 F_32 ( struct V_1 * V_1 , char T_4 * V_53 , T_3 V_44 ,
T_1 * V_45 )
{
if ( V_1 -> V_30 -> V_59 )
return V_1 -> V_30 -> V_59 ( V_1 , V_53 , V_44 , V_45 ) ;
else if ( V_1 -> V_30 -> V_37 )
return F_30 ( V_1 , V_53 , V_44 , V_45 ) ;
else
return - V_6 ;
}
T_2 F_33 ( struct V_1 * V_1 , char T_4 * V_53 , T_3 V_44 , T_1 * V_45 )
{
T_2 V_36 ;
if ( ! ( V_1 -> V_2 & V_60 ) )
return - V_61 ;
if ( ! ( V_1 -> V_2 & V_62 ) )
return - V_6 ;
if ( F_26 ( ! F_34 ( V_63 , V_53 , V_44 ) ) )
return - V_64 ;
V_36 = F_25 ( V_39 , V_1 , V_45 , V_44 ) ;
if ( ! V_36 ) {
if ( V_44 > V_65 )
V_44 = V_65 ;
V_36 = F_32 ( V_1 , V_53 , V_44 , V_45 ) ;
if ( V_36 > 0 ) {
F_35 ( V_1 ) ;
F_36 ( V_66 , V_36 ) ;
}
F_37 ( V_66 ) ;
}
return V_36 ;
}
static T_2 F_38 ( struct V_1 * V_52 , const char T_4 * V_53 , T_3 V_54 , T_1 * V_34 )
{
struct V_55 V_56 = { . V_57 = ( void T_4 * ) V_53 , . V_58 = V_54 } ;
struct V_35 V_35 ;
struct V_32 V_33 ;
T_2 V_36 ;
F_20 ( & V_35 , V_52 ) ;
V_35 . V_38 = * V_34 ;
F_31 ( & V_33 , V_42 , & V_56 , 1 , V_54 ) ;
V_36 = F_24 ( V_52 , & V_35 , & V_33 ) ;
F_22 ( V_36 == - V_40 ) ;
if ( V_36 > 0 )
* V_34 = V_35 . V_38 ;
return V_36 ;
}
T_2 F_39 ( struct V_1 * V_1 , const char T_4 * V_67 , T_3 V_44 ,
T_1 * V_45 )
{
if ( V_1 -> V_30 -> V_68 )
return V_1 -> V_30 -> V_68 ( V_1 , V_67 , V_44 , V_45 ) ;
else if ( V_1 -> V_30 -> V_41 )
return F_38 ( V_1 , V_67 , V_44 , V_45 ) ;
else
return - V_6 ;
}
T_2 F_40 ( struct V_1 * V_1 , const char * V_53 , T_3 V_44 , T_1 * V_45 )
{
T_5 V_69 ;
const char T_4 * V_67 ;
T_2 V_36 ;
if ( ! ( V_1 -> V_2 & V_70 ) )
return - V_6 ;
V_69 = F_41 () ;
F_42 ( F_43 () ) ;
V_67 = ( V_71 const char T_4 * ) V_53 ;
if ( V_44 > V_65 )
V_44 = V_65 ;
V_36 = F_39 ( V_1 , V_67 , V_44 , V_45 ) ;
F_42 ( V_69 ) ;
if ( V_36 > 0 ) {
F_44 ( V_1 ) ;
F_45 ( V_66 , V_36 ) ;
}
F_46 ( V_66 ) ;
return V_36 ;
}
T_2 F_47 ( struct V_1 * V_1 , const char T_4 * V_53 , T_3 V_44 , T_1 * V_45 )
{
T_2 V_36 ;
if ( ! ( V_1 -> V_2 & V_72 ) )
return - V_61 ;
if ( ! ( V_1 -> V_2 & V_70 ) )
return - V_6 ;
if ( F_26 ( ! F_34 ( V_73 , V_53 , V_44 ) ) )
return - V_64 ;
V_36 = F_25 ( V_42 , V_1 , V_45 , V_44 ) ;
if ( ! V_36 ) {
if ( V_44 > V_65 )
V_44 = V_65 ;
F_48 ( V_1 ) ;
V_36 = F_39 ( V_1 , V_53 , V_44 , V_45 ) ;
if ( V_36 > 0 ) {
F_44 ( V_1 ) ;
F_45 ( V_66 , V_36 ) ;
}
F_46 ( V_66 ) ;
F_49 ( V_1 ) ;
}
return V_36 ;
}
static inline T_1 F_50 ( struct V_1 * V_1 )
{
return V_1 -> V_7 ;
}
static inline void F_51 ( struct V_1 * V_1 , T_1 V_45 )
{
V_1 -> V_7 = V_45 ;
}
unsigned long F_52 ( struct V_55 * V_56 , unsigned long V_74 , T_3 V_75 )
{
unsigned long V_76 = 0 ;
T_3 V_54 = 0 ;
while ( V_76 < V_74 ) {
V_76 ++ ;
if ( V_54 + V_56 -> V_58 >= V_75 ) {
V_56 -> V_58 = V_75 - V_54 ;
break;
}
V_54 += V_56 -> V_58 ;
V_56 ++ ;
}
return V_76 ;
}
static T_2 F_53 ( struct V_1 * V_52 , struct V_32 * V_33 ,
T_1 * V_34 , int type , int V_77 )
{
struct V_35 V_35 ;
T_2 V_36 ;
if ( V_77 & ~ ( V_78 | V_79 | V_80 ) )
return - V_81 ;
F_20 ( & V_35 , V_52 ) ;
if ( V_77 & V_78 )
V_35 . V_82 |= V_83 ;
if ( V_77 & V_79 )
V_35 . V_82 |= V_84 ;
if ( V_77 & V_80 )
V_35 . V_82 |= ( V_84 | V_85 ) ;
V_35 . V_38 = * V_34 ;
if ( type == V_39 )
V_36 = F_21 ( V_52 , & V_35 , V_33 ) ;
else
V_36 = F_24 ( V_52 , & V_35 , V_33 ) ;
F_22 ( V_36 == - V_40 ) ;
* V_34 = V_35 . V_38 ;
return V_36 ;
}
static T_2 F_54 ( struct V_1 * V_52 , struct V_32 * V_33 ,
T_1 * V_34 , int type , int V_77 )
{
T_2 V_36 = 0 ;
if ( V_77 & ~ V_78 )
return - V_81 ;
while ( F_55 ( V_33 ) ) {
struct V_55 V_55 = F_56 ( V_33 ) ;
T_2 V_86 ;
if ( type == V_39 ) {
V_86 = V_52 -> V_30 -> V_59 ( V_52 , V_55 . V_57 ,
V_55 . V_58 , V_34 ) ;
} else {
V_86 = V_52 -> V_30 -> V_68 ( V_52 , V_55 . V_57 ,
V_55 . V_58 , V_34 ) ;
}
if ( V_86 < 0 ) {
if ( ! V_36 )
V_36 = V_86 ;
break;
}
V_36 += V_86 ;
if ( V_86 != V_55 . V_58 )
break;
F_57 ( V_33 , V_86 ) ;
}
return V_36 ;
}
T_2 F_58 ( int type , const struct V_55 T_4 * V_87 ,
unsigned long V_74 , unsigned long V_88 ,
struct V_55 * V_89 ,
struct V_55 * * V_90 )
{
unsigned long V_76 ;
T_2 V_36 ;
struct V_55 * V_56 = V_89 ;
if ( V_74 == 0 ) {
V_36 = 0 ;
goto V_27;
}
if ( V_74 > V_91 ) {
V_36 = - V_6 ;
goto V_27;
}
if ( V_74 > V_88 ) {
V_56 = F_59 ( V_74 * sizeof( struct V_55 ) , V_92 ) ;
if ( V_56 == NULL ) {
V_36 = - V_93 ;
goto V_27;
}
}
if ( F_60 ( V_56 , V_87 , V_74 * sizeof( * V_87 ) ) ) {
V_36 = - V_64 ;
goto V_27;
}
V_36 = 0 ;
for ( V_76 = 0 ; V_76 < V_74 ; V_76 ++ ) {
void T_4 * V_53 = V_56 [ V_76 ] . V_57 ;
T_2 V_54 = ( T_2 ) V_56 [ V_76 ] . V_58 ;
if ( V_54 < 0 ) {
V_36 = - V_6 ;
goto V_27;
}
if ( type >= 0
&& F_26 ( ! F_34 ( F_61 ( type ) , V_53 , V_54 ) ) ) {
V_36 = - V_64 ;
goto V_27;
}
if ( V_54 > V_65 - V_36 ) {
V_54 = V_65 - V_36 ;
V_56 [ V_76 ] . V_58 = V_54 ;
}
V_36 += V_54 ;
}
V_27:
* V_90 = V_56 ;
return V_36 ;
}
static T_2 F_62 ( int type , struct V_1 * V_1 ,
struct V_32 * V_33 , T_1 * V_45 , int V_77 )
{
T_3 V_94 ;
T_2 V_36 = 0 ;
V_94 = F_55 ( V_33 ) ;
if ( ! V_94 )
goto V_27;
V_36 = F_25 ( type , V_1 , V_45 , V_94 ) ;
if ( V_36 < 0 )
goto V_27;
if ( type != V_39 )
F_48 ( V_1 ) ;
if ( ( type == V_39 && V_1 -> V_30 -> V_37 ) ||
( type == V_42 && V_1 -> V_30 -> V_41 ) )
V_36 = F_53 ( V_1 , V_33 , V_45 , type , V_77 ) ;
else
V_36 = F_54 ( V_1 , V_33 , V_45 , type , V_77 ) ;
if ( type != V_39 )
F_49 ( V_1 ) ;
V_27:
if ( ( V_36 + ( type == V_39 ) ) > 0 ) {
if ( type == V_39 )
F_35 ( V_1 ) ;
else
F_44 ( V_1 ) ;
}
return V_36 ;
}
static T_2 F_63 ( int type , struct V_1 * V_1 ,
const struct V_55 T_4 * V_87 ,
unsigned long V_74 , T_1 * V_45 ,
int V_77 )
{
struct V_55 V_95 [ V_96 ] ;
struct V_55 * V_56 = V_95 ;
struct V_32 V_33 ;
T_2 V_36 ;
V_36 = F_64 ( type , V_87 , V_74 ,
F_65 ( V_95 ) , & V_56 , & V_33 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_62 ( type , V_1 , & V_33 , V_45 , V_77 ) ;
F_66 ( V_56 ) ;
return V_36 ;
}
T_2 F_67 ( struct V_1 * V_1 , const struct V_55 T_4 * V_97 ,
unsigned long V_98 , T_1 * V_45 , int V_77 )
{
if ( ! ( V_1 -> V_2 & V_60 ) )
return - V_61 ;
if ( ! ( V_1 -> V_2 & V_62 ) )
return - V_6 ;
return F_63 ( V_39 , V_1 , V_97 , V_98 , V_45 , V_77 ) ;
}
T_2 F_68 ( struct V_1 * V_1 , const struct V_55 T_4 * V_97 ,
unsigned long V_98 , T_1 * V_45 , int V_77 )
{
if ( ! ( V_1 -> V_2 & V_72 ) )
return - V_61 ;
if ( ! ( V_1 -> V_2 & V_70 ) )
return - V_6 ;
return F_63 ( V_42 , V_1 , V_97 , V_98 , V_45 , V_77 ) ;
}
static T_2 F_69 ( unsigned long V_99 , const struct V_55 T_4 * V_97 ,
unsigned long V_98 , int V_77 )
{
struct V_99 V_100 = F_70 ( V_99 ) ;
T_2 V_36 = - V_61 ;
if ( V_100 . V_1 ) {
T_1 V_45 = F_50 ( V_100 . V_1 ) ;
V_36 = F_67 ( V_100 . V_1 , V_97 , V_98 , & V_45 , V_77 ) ;
if ( V_36 >= 0 )
F_51 ( V_100 . V_1 , V_45 ) ;
F_71 ( V_100 ) ;
}
if ( V_36 > 0 )
F_36 ( V_66 , V_36 ) ;
F_37 ( V_66 ) ;
return V_36 ;
}
static T_2 F_72 ( unsigned long V_99 , const struct V_55 T_4 * V_97 ,
unsigned long V_98 , int V_77 )
{
struct V_99 V_100 = F_70 ( V_99 ) ;
T_2 V_36 = - V_61 ;
if ( V_100 . V_1 ) {
T_1 V_45 = F_50 ( V_100 . V_1 ) ;
V_36 = F_68 ( V_100 . V_1 , V_97 , V_98 , & V_45 , V_77 ) ;
if ( V_36 >= 0 )
F_51 ( V_100 . V_1 , V_45 ) ;
F_71 ( V_100 ) ;
}
if ( V_36 > 0 )
F_45 ( V_66 , V_36 ) ;
F_46 ( V_66 ) ;
return V_36 ;
}
static inline T_1 F_73 ( unsigned long V_101 , unsigned long V_102 )
{
#define F_74 (BITS_PER_LONG / 2)
return ( ( ( T_1 ) V_101 << F_74 ) << F_74 ) | V_102 ;
}
static T_2 F_75 ( unsigned long V_99 , const struct V_55 T_4 * V_97 ,
unsigned long V_98 , T_1 V_45 , int V_77 )
{
struct V_99 V_100 ;
T_2 V_36 = - V_61 ;
if ( V_45 < 0 )
return - V_6 ;
V_100 = F_76 ( V_99 ) ;
if ( V_100 . V_1 ) {
V_36 = - V_25 ;
if ( V_100 . V_1 -> V_2 & V_103 )
V_36 = F_67 ( V_100 . V_1 , V_97 , V_98 , & V_45 , V_77 ) ;
F_77 ( V_100 ) ;
}
if ( V_36 > 0 )
F_36 ( V_66 , V_36 ) ;
F_37 ( V_66 ) ;
return V_36 ;
}
static T_2 F_78 ( unsigned long V_99 , const struct V_55 T_4 * V_97 ,
unsigned long V_98 , T_1 V_45 , int V_77 )
{
struct V_99 V_100 ;
T_2 V_36 = - V_61 ;
if ( V_45 < 0 )
return - V_6 ;
V_100 = F_76 ( V_99 ) ;
if ( V_100 . V_1 ) {
V_36 = - V_25 ;
if ( V_100 . V_1 -> V_2 & V_104 )
V_36 = F_68 ( V_100 . V_1 , V_97 , V_98 , & V_45 , V_77 ) ;
F_77 ( V_100 ) ;
}
if ( V_36 > 0 )
F_45 ( V_66 , V_36 ) ;
F_46 ( V_66 ) ;
return V_36 ;
}
static T_2 F_79 ( int type , struct V_1 * V_1 ,
const struct V_105 T_4 * V_87 ,
unsigned long V_74 , T_1 * V_45 ,
int V_77 )
{
struct V_55 V_95 [ V_96 ] ;
struct V_55 * V_56 = V_95 ;
struct V_32 V_33 ;
T_2 V_36 ;
V_36 = F_80 ( type , V_87 , V_74 ,
V_96 , & V_56 , & V_33 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_62 ( type , V_1 , & V_33 , V_45 , V_77 ) ;
F_66 ( V_56 ) ;
return V_36 ;
}
static T_3 F_81 ( struct V_1 * V_1 ,
const struct V_105 T_4 * V_97 ,
unsigned long V_98 , T_1 * V_45 , int V_77 )
{
T_2 V_36 = - V_61 ;
if ( ! ( V_1 -> V_2 & V_60 ) )
goto V_27;
V_36 = - V_6 ;
if ( ! ( V_1 -> V_2 & V_62 ) )
goto V_27;
V_36 = F_79 ( V_39 , V_1 , V_97 , V_98 , V_45 , V_77 ) ;
V_27:
if ( V_36 > 0 )
F_36 ( V_66 , V_36 ) ;
F_37 ( V_66 ) ;
return V_36 ;
}
static T_3 F_82 ( T_6 V_99 ,
const struct V_105 T_4 * V_97 ,
T_6 V_98 , int V_77 )
{
struct V_99 V_100 = F_70 ( V_99 ) ;
T_2 V_36 ;
T_1 V_45 ;
if ( ! V_100 . V_1 )
return - V_61 ;
V_45 = V_100 . V_1 -> V_7 ;
V_36 = F_81 ( V_100 . V_1 , V_97 , V_98 , & V_45 , V_77 ) ;
if ( V_36 >= 0 )
V_100 . V_1 -> V_7 = V_45 ;
F_71 ( V_100 ) ;
return V_36 ;
}
static long F_83 ( unsigned long V_99 ,
const struct V_105 T_4 * V_97 ,
unsigned long V_98 , T_1 V_45 , int V_77 )
{
struct V_99 V_100 ;
T_2 V_36 ;
if ( V_45 < 0 )
return - V_6 ;
V_100 = F_76 ( V_99 ) ;
if ( ! V_100 . V_1 )
return - V_61 ;
V_36 = - V_25 ;
if ( V_100 . V_1 -> V_2 & V_103 )
V_36 = F_81 ( V_100 . V_1 , V_97 , V_98 , & V_45 , V_77 ) ;
F_77 ( V_100 ) ;
return V_36 ;
}
static T_3 F_84 ( struct V_1 * V_1 ,
const struct V_105 T_4 * V_97 ,
unsigned long V_98 , T_1 * V_45 , int V_77 )
{
T_2 V_36 = - V_61 ;
if ( ! ( V_1 -> V_2 & V_72 ) )
goto V_27;
V_36 = - V_6 ;
if ( ! ( V_1 -> V_2 & V_70 ) )
goto V_27;
V_36 = F_79 ( V_42 , V_1 , V_97 , V_98 , V_45 , 0 ) ;
V_27:
if ( V_36 > 0 )
F_45 ( V_66 , V_36 ) ;
F_46 ( V_66 ) ;
return V_36 ;
}
static T_3 F_85 ( T_6 V_99 ,
const struct V_105 T_4 * V_97 ,
T_6 V_98 , int V_77 )
{
struct V_99 V_100 = F_70 ( V_99 ) ;
T_2 V_36 ;
T_1 V_45 ;
if ( ! V_100 . V_1 )
return - V_61 ;
V_45 = V_100 . V_1 -> V_7 ;
V_36 = F_84 ( V_100 . V_1 , V_97 , V_98 , & V_45 , V_77 ) ;
if ( V_36 >= 0 )
V_100 . V_1 -> V_7 = V_45 ;
F_71 ( V_100 ) ;
return V_36 ;
}
static long F_86 ( unsigned long V_99 ,
const struct V_105 T_4 * V_97 ,
unsigned long V_98 , T_1 V_45 , int V_77 )
{
struct V_99 V_100 ;
T_2 V_36 ;
if ( V_45 < 0 )
return - V_6 ;
V_100 = F_76 ( V_99 ) ;
if ( ! V_100 . V_1 )
return - V_61 ;
V_36 = - V_25 ;
if ( V_100 . V_1 -> V_2 & V_104 )
V_36 = F_84 ( V_100 . V_1 , V_97 , V_98 , & V_45 , V_77 ) ;
F_77 ( V_100 ) ;
return V_36 ;
}
static T_2 F_87 ( int V_106 , int V_107 , T_1 * V_34 ,
T_3 V_44 , T_1 V_108 )
{
struct V_99 V_109 , V_27 ;
struct V_17 * V_110 , * V_111 ;
T_1 V_45 ;
T_1 V_112 ;
T_2 V_26 ;
int V_113 ;
V_26 = - V_61 ;
V_109 = F_76 ( V_107 ) ;
if ( ! V_109 . V_1 )
goto V_27;
if ( ! ( V_109 . V_1 -> V_2 & V_60 ) )
goto V_114;
V_26 = - V_25 ;
if ( ! V_34 ) {
V_45 = V_109 . V_1 -> V_7 ;
} else {
V_45 = * V_34 ;
if ( ! ( V_109 . V_1 -> V_2 & V_103 ) )
goto V_114;
}
V_26 = F_25 ( V_39 , V_109 . V_1 , & V_45 , V_44 ) ;
if ( V_26 < 0 )
goto V_114;
if ( V_44 > V_65 )
V_44 = V_65 ;
V_26 = - V_61 ;
V_27 = F_76 ( V_106 ) ;
if ( ! V_27 . V_1 )
goto V_114;
if ( ! ( V_27 . V_1 -> V_2 & V_72 ) )
goto V_115;
V_26 = - V_6 ;
V_110 = F_14 ( V_109 . V_1 ) ;
V_111 = F_14 ( V_27 . V_1 ) ;
V_112 = V_27 . V_1 -> V_7 ;
V_26 = F_25 ( V_42 , V_27 . V_1 , & V_112 , V_44 ) ;
if ( V_26 < 0 )
goto V_115;
if ( ! V_108 )
V_108 = F_88 ( V_110 -> V_20 -> V_21 , V_111 -> V_20 -> V_21 ) ;
if ( F_26 ( V_45 + V_44 > V_108 ) ) {
V_26 = - V_46 ;
if ( V_45 >= V_108 )
goto V_115;
V_44 = V_108 - V_45 ;
}
V_113 = 0 ;
#if 0
if (in.file->f_flags & O_NONBLOCK)
fl = SPLICE_F_NONBLOCK;
#endif
F_48 ( V_27 . V_1 ) ;
V_26 = F_89 ( V_109 . V_1 , & V_45 , V_27 . V_1 , & V_112 , V_44 , V_113 ) ;
F_49 ( V_27 . V_1 ) ;
if ( V_26 > 0 ) {
F_36 ( V_66 , V_26 ) ;
F_45 ( V_66 , V_26 ) ;
F_35 ( V_109 . V_1 ) ;
F_44 ( V_27 . V_1 ) ;
V_27 . V_1 -> V_7 = V_112 ;
if ( V_34 )
* V_34 = V_45 ;
else
V_109 . V_1 -> V_7 = V_45 ;
}
F_37 ( V_66 ) ;
F_46 ( V_66 ) ;
if ( V_45 > V_108 )
V_26 = - V_46 ;
V_115:
F_77 ( V_27 ) ;
V_114:
F_77 ( V_109 ) ;
V_27:
return V_26 ;
}
T_2 F_90 ( struct V_1 * V_116 , T_1 V_117 ,
struct V_1 * V_118 , T_1 V_119 ,
T_3 V_54 , unsigned int V_77 )
{
struct V_17 * V_120 = F_14 ( V_116 ) ;
struct V_17 * V_121 = F_14 ( V_118 ) ;
T_2 V_36 ;
if ( V_77 != 0 )
return - V_6 ;
if ( F_91 ( V_120 -> V_122 ) || F_91 ( V_121 -> V_122 ) )
return - V_123 ;
if ( ! F_92 ( V_120 -> V_122 ) || ! F_92 ( V_121 -> V_122 ) )
return - V_6 ;
V_36 = F_25 ( V_39 , V_116 , & V_117 , V_54 ) ;
if ( F_26 ( V_36 ) )
return V_36 ;
V_36 = F_25 ( V_42 , V_118 , & V_119 , V_54 ) ;
if ( F_26 ( V_36 ) )
return V_36 ;
if ( ! ( V_116 -> V_2 & V_60 ) ||
! ( V_118 -> V_2 & V_72 ) ||
( V_118 -> V_124 & V_125 ) )
return - V_61 ;
if ( V_120 -> V_20 != V_121 -> V_20 )
return - V_126 ;
if ( V_54 == 0 )
return 0 ;
F_48 ( V_118 ) ;
if ( V_116 -> V_30 -> V_127 ) {
V_36 = V_116 -> V_30 -> V_127 ( V_116 , V_117 ,
V_118 , V_119 , V_54 ) ;
if ( V_36 == 0 ) {
V_36 = V_54 ;
goto V_128;
}
}
if ( V_118 -> V_30 -> V_129 ) {
V_36 = V_118 -> V_30 -> V_129 ( V_116 , V_117 , V_118 ,
V_119 , V_54 , V_77 ) ;
if ( V_36 != - V_81 )
goto V_128;
}
V_36 = F_89 ( V_116 , & V_117 , V_118 , & V_119 ,
V_54 > V_65 ? V_65 : V_54 , 0 ) ;
V_128:
if ( V_36 > 0 ) {
F_35 ( V_116 ) ;
F_36 ( V_66 , V_36 ) ;
F_44 ( V_118 ) ;
F_45 ( V_66 , V_36 ) ;
}
F_37 ( V_66 ) ;
F_46 ( V_66 ) ;
F_49 ( V_118 ) ;
return V_36 ;
}
static int F_93 ( struct V_1 * V_1 , T_1 V_45 , T_7 V_54 , bool V_68 )
{
struct V_17 * V_17 = F_14 ( V_1 ) ;
if ( F_26 ( V_45 < 0 ) )
return - V_6 ;
if ( F_26 ( ( T_1 ) ( V_45 + V_54 ) < 0 ) )
return - V_6 ;
if ( F_26 ( V_17 -> V_47 && F_27 ( V_17 ) ) ) {
T_1 V_130 = V_54 ? V_45 + V_54 - 1 : V_24 ;
int V_26 ;
V_26 = F_28 ( V_17 , V_1 , V_45 , V_130 ,
V_68 ? V_49 : V_48 ) ;
if ( V_26 < 0 )
return V_26 ;
}
return F_29 ( V_1 , V_68 ? V_51 : V_50 ) ;
}
int F_94 ( struct V_17 * V_120 , T_1 V_117 ,
struct V_17 * V_121 , T_1 V_119 ,
T_7 * V_54 , bool V_131 )
{
T_1 V_132 = V_121 -> V_20 -> V_133 ;
T_1 V_134 ;
T_1 V_135 ;
bool V_136 = ( V_120 == V_121 ) ;
int V_36 ;
if ( F_95 ( V_121 ) )
return - V_137 ;
if ( F_96 ( V_120 ) || F_96 ( V_121 ) )
return - V_138 ;
if ( F_91 ( V_120 -> V_122 ) || F_91 ( V_121 -> V_122 ) )
return - V_123 ;
if ( ! F_92 ( V_120 -> V_122 ) || ! F_92 ( V_121 -> V_122 ) )
return - V_6 ;
V_135 = F_7 ( V_120 ) ;
if ( V_135 == 0 )
return 0 ;
if ( * V_54 == 0 ) {
if ( V_131 || V_117 == V_135 )
return 0 ;
if ( V_117 > V_135 )
return - V_6 ;
* V_54 = V_135 - V_117 ;
}
if ( V_117 + * V_54 < V_117 || V_119 + * V_54 < V_119 ||
V_117 + * V_54 > V_135 )
return - V_6 ;
if ( V_131 ) {
T_1 V_139 ;
V_139 = F_7 ( V_121 ) ;
if ( V_119 >= V_139 || V_119 + * V_54 > V_139 )
return - V_6 ;
}
if ( V_117 + * V_54 == V_135 )
V_134 = F_97 ( V_135 , V_132 ) - V_117 ;
else
V_134 = * V_54 ;
if ( ! F_98 ( V_117 , V_132 ) || ! F_98 ( V_117 + V_134 , V_132 ) ||
! F_98 ( V_119 , V_132 ) || ! F_98 ( V_119 + V_134 , V_132 ) )
return - V_6 ;
if ( V_136 ) {
if ( V_119 + V_134 > V_117 && V_119 < V_117 + V_134 )
return - V_6 ;
}
F_99 ( V_120 ) ;
if ( ! V_136 )
F_99 ( V_121 ) ;
V_36 = F_100 ( V_120 -> V_140 ,
V_117 , V_117 + * V_54 - 1 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_100 ( V_121 -> V_140 ,
V_119 , V_119 + * V_54 - 1 ) ;
if ( V_36 )
return V_36 ;
if ( V_131 ) {
bool V_141 = false ;
V_36 = F_101 ( V_120 , V_117 ,
V_121 , V_119 , * V_54 , & V_141 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_141 )
return - V_142 ;
}
return 1 ;
}
int F_102 ( struct V_1 * V_116 , T_1 V_117 ,
struct V_1 * V_118 , T_1 V_119 , T_7 V_54 )
{
struct V_17 * V_120 = F_14 ( V_116 ) ;
struct V_17 * V_121 = F_14 ( V_118 ) ;
int V_36 ;
if ( F_91 ( V_120 -> V_122 ) || F_91 ( V_121 -> V_122 ) )
return - V_123 ;
if ( ! F_92 ( V_120 -> V_122 ) || ! F_92 ( V_121 -> V_122 ) )
return - V_6 ;
if ( V_120 -> V_20 != V_121 -> V_20 )
return - V_126 ;
if ( ! ( V_116 -> V_2 & V_60 ) ||
! ( V_118 -> V_2 & V_72 ) ||
( V_118 -> V_124 & V_125 ) )
return - V_61 ;
if ( ! V_116 -> V_30 -> V_127 )
return - V_81 ;
V_36 = F_93 ( V_116 , V_117 , V_54 , false ) ;
if ( V_36 )
return V_36 ;
V_36 = F_93 ( V_118 , V_119 , V_54 , true ) ;
if ( V_36 )
return V_36 ;
if ( V_117 + V_54 > F_7 ( V_120 ) )
return - V_6 ;
V_36 = V_116 -> V_30 -> V_127 ( V_116 , V_117 ,
V_118 , V_119 , V_54 ) ;
if ( ! V_36 ) {
F_35 ( V_116 ) ;
F_44 ( V_118 ) ;
}
return V_36 ;
}
static struct V_143 * F_103 ( struct V_17 * V_17 , T_1 V_4 )
{
struct V_144 * V_145 ;
struct V_143 * V_143 ;
T_8 V_146 ;
V_146 = V_4 >> V_147 ;
V_145 = V_17 -> V_140 ;
V_143 = F_104 ( V_145 , V_146 , NULL ) ;
if ( F_105 ( V_143 ) )
return V_143 ;
if ( ! F_106 ( V_143 ) ) {
F_107 ( V_143 ) ;
return F_108 ( - V_148 ) ;
}
F_109 ( V_143 ) ;
return V_143 ;
}
int F_101 ( struct V_17 * V_149 , T_1 V_150 ,
struct V_17 * V_151 , T_1 V_152 ,
T_1 V_54 , bool * V_141 )
{
T_1 V_153 ;
T_1 V_154 ;
void * V_155 ;
void * V_156 ;
struct V_143 * V_157 ;
struct V_143 * V_158 ;
T_1 V_159 ;
bool V_160 ;
int error ;
error = - V_6 ;
V_160 = true ;
while ( V_54 ) {
V_153 = V_150 & ( V_161 - 1 ) ;
V_154 = V_152 & ( V_161 - 1 ) ;
V_159 = F_88 ( V_161 - V_153 ,
V_161 - V_154 ) ;
V_159 = F_88 ( V_159 , V_54 ) ;
if ( V_159 <= 0 )
goto V_162;
V_157 = F_103 ( V_149 , V_150 ) ;
if ( F_105 ( V_157 ) ) {
error = F_110 ( V_157 ) ;
goto V_162;
}
V_158 = F_103 ( V_151 , V_152 ) ;
if ( F_105 ( V_158 ) ) {
error = F_110 ( V_158 ) ;
F_111 ( V_157 ) ;
F_107 ( V_157 ) ;
goto V_162;
}
V_155 = F_112 ( V_157 ) ;
V_156 = F_112 ( V_158 ) ;
F_113 ( V_157 ) ;
F_113 ( V_158 ) ;
if ( memcmp ( V_155 + V_153 , V_156 + V_154 , V_159 ) )
V_160 = false ;
F_114 ( V_156 ) ;
F_114 ( V_155 ) ;
F_111 ( V_158 ) ;
F_111 ( V_157 ) ;
F_107 ( V_158 ) ;
F_107 ( V_157 ) ;
if ( ! V_160 )
break;
V_150 += V_159 ;
V_152 += V_159 ;
V_54 -= V_159 ;
}
* V_141 = V_160 ;
return 0 ;
V_162:
return error ;
}
int F_115 ( struct V_1 * V_1 , struct V_163 * V_160 )
{
struct V_164 * V_165 ;
struct V_17 * V_149 = F_14 ( V_1 ) ;
T_7 V_166 ;
T_7 V_54 ;
int V_167 ;
int V_36 ;
bool V_168 = F_116 ( V_169 ) ;
T_9 V_44 = V_160 -> V_170 ;
struct V_1 * V_171 ;
T_1 V_172 ;
T_2 V_173 ;
if ( ! ( V_1 -> V_2 & V_60 ) )
return - V_6 ;
if ( V_160 -> V_174 || V_160 -> V_175 )
return - V_6 ;
V_166 = V_160 -> V_176 ;
V_54 = V_160 -> V_177 ;
V_36 = - V_123 ;
if ( F_91 ( V_149 -> V_122 ) )
goto V_27;
V_36 = - V_6 ;
if ( ! F_92 ( V_149 -> V_122 ) )
goto V_27;
V_36 = F_93 ( V_1 , V_166 , V_54 , false ) ;
if ( V_36 < 0 )
goto V_27;
V_36 = 0 ;
if ( V_166 + V_54 > F_7 ( V_149 ) )
return - V_6 ;
for ( V_167 = 0 ; V_167 < V_44 ; V_167 ++ ) {
V_160 -> V_165 [ V_167 ] . V_178 = 0ULL ;
V_160 -> V_165 [ V_167 ] . V_179 = V_180 ;
}
for ( V_167 = 0 , V_165 = V_160 -> V_165 ; V_167 < V_44 ; V_167 ++ , V_165 ++ ) {
struct V_17 * V_181 ;
struct V_99 V_182 = F_76 ( V_165 -> V_183 ) ;
V_171 = V_182 . V_1 ;
if ( ! V_171 ) {
V_165 -> V_179 = - V_61 ;
goto V_184;
}
V_181 = F_14 ( V_171 ) ;
V_36 = F_117 ( V_171 ) ;
if ( V_36 ) {
V_165 -> V_179 = V_36 ;
goto V_184;
}
V_172 = V_165 -> V_185 ;
V_36 = F_93 ( V_171 , V_172 , V_54 , true ) ;
if ( V_36 < 0 ) {
V_165 -> V_179 = V_36 ;
goto V_186;
}
V_36 = 0 ;
if ( V_165 -> V_187 ) {
V_165 -> V_179 = - V_6 ;
} else if ( ! ( V_168 || ( V_171 -> V_2 & V_72 ) ) ) {
V_165 -> V_179 = - V_6 ;
} else if ( V_1 -> V_188 . V_189 != V_171 -> V_188 . V_189 ) {
V_165 -> V_179 = - V_126 ;
} else if ( F_91 ( V_181 -> V_122 ) ) {
V_165 -> V_179 = - V_123 ;
} else if ( V_171 -> V_30 -> V_190 == NULL ) {
V_165 -> V_179 = - V_6 ;
} else {
V_173 = V_171 -> V_30 -> V_190 ( V_1 , V_166 ,
V_54 , V_171 ,
V_165 -> V_185 ) ;
if ( V_173 == - V_142 )
V_165 -> V_179 = V_191 ;
else if ( V_173 < 0 )
V_165 -> V_179 = V_173 ;
else
V_165 -> V_178 += V_173 ;
}
V_186:
F_118 ( V_171 ) ;
V_184:
F_77 ( V_182 ) ;
if ( F_119 ( V_66 ) )
goto V_27;
}
V_27:
return V_36 ;
}
