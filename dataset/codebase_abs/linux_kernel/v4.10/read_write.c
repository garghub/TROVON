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
V_36 = V_1 -> V_30 -> V_37 ( & V_35 , V_33 ) ;
F_21 ( V_36 == - V_40 ) ;
if ( V_36 > 0 )
* V_34 = V_35 . V_38 ;
return V_36 ;
}
T_2 F_22 ( struct V_1 * V_1 , struct V_32 * V_33 , T_1 * V_34 )
{
struct V_35 V_35 ;
T_2 V_36 ;
if ( ! V_1 -> V_30 -> V_41 )
return - V_6 ;
F_20 ( & V_35 , V_1 ) ;
V_35 . V_38 = * V_34 ;
V_33 -> type |= V_42 ;
V_36 = V_1 -> V_30 -> V_41 ( & V_35 , V_33 ) ;
F_21 ( V_36 == - V_40 ) ;
if ( V_36 > 0 )
* V_34 = V_35 . V_38 ;
return V_36 ;
}
int F_23 ( int V_43 , struct V_1 * V_1 , const T_1 * V_34 , T_3 V_44 )
{
struct V_17 * V_17 ;
T_1 V_45 ;
int V_26 = - V_6 ;
V_17 = F_14 ( V_1 ) ;
if ( F_24 ( ( T_2 ) V_44 < 0 ) )
return V_26 ;
V_45 = * V_34 ;
if ( F_24 ( V_45 < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_26 ;
if ( V_44 >= - V_45 )
return - V_46 ;
} else if ( F_24 ( ( T_1 ) ( V_45 + V_44 ) < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_26 ;
}
if ( F_24 ( V_17 -> V_47 && F_25 ( V_17 ) ) ) {
V_26 = F_26 ( V_17 , V_1 , V_45 , V_45 + V_44 - 1 ,
V_43 == V_39 ? V_48 : V_49 ) ;
if ( V_26 < 0 )
return V_26 ;
}
return F_27 ( V_1 ,
V_43 == V_39 ? V_50 : V_51 ) ;
}
static T_2 F_28 ( struct V_1 * V_52 , char T_4 * V_53 , T_3 V_54 , T_1 * V_34 )
{
struct V_55 V_56 = { . V_57 = V_53 , . V_58 = V_54 } ;
struct V_35 V_35 ;
struct V_32 V_33 ;
T_2 V_36 ;
F_20 ( & V_35 , V_52 ) ;
V_35 . V_38 = * V_34 ;
F_29 ( & V_33 , V_39 , & V_56 , 1 , V_54 ) ;
V_36 = V_52 -> V_30 -> V_37 ( & V_35 , & V_33 ) ;
F_21 ( V_36 == - V_40 ) ;
* V_34 = V_35 . V_38 ;
return V_36 ;
}
T_2 F_30 ( struct V_1 * V_1 , char T_4 * V_53 , T_3 V_44 ,
T_1 * V_45 )
{
if ( V_1 -> V_30 -> V_59 )
return V_1 -> V_30 -> V_59 ( V_1 , V_53 , V_44 , V_45 ) ;
else if ( V_1 -> V_30 -> V_37 )
return F_28 ( V_1 , V_53 , V_44 , V_45 ) ;
else
return - V_6 ;
}
T_2 F_31 ( struct V_1 * V_1 , char T_4 * V_53 , T_3 V_44 , T_1 * V_45 )
{
T_2 V_36 ;
if ( ! ( V_1 -> V_2 & V_60 ) )
return - V_61 ;
if ( ! ( V_1 -> V_2 & V_62 ) )
return - V_6 ;
if ( F_24 ( ! F_32 ( V_63 , V_53 , V_44 ) ) )
return - V_64 ;
V_36 = F_23 ( V_39 , V_1 , V_45 , V_44 ) ;
if ( ! V_36 ) {
if ( V_44 > V_65 )
V_44 = V_65 ;
V_36 = F_30 ( V_1 , V_53 , V_44 , V_45 ) ;
if ( V_36 > 0 ) {
F_33 ( V_1 ) ;
F_34 ( V_66 , V_36 ) ;
}
F_35 ( V_66 ) ;
}
return V_36 ;
}
static T_2 F_36 ( struct V_1 * V_52 , const char T_4 * V_53 , T_3 V_54 , T_1 * V_34 )
{
struct V_55 V_56 = { . V_57 = ( void T_4 * ) V_53 , . V_58 = V_54 } ;
struct V_35 V_35 ;
struct V_32 V_33 ;
T_2 V_36 ;
F_20 ( & V_35 , V_52 ) ;
V_35 . V_38 = * V_34 ;
F_29 ( & V_33 , V_42 , & V_56 , 1 , V_54 ) ;
V_36 = V_52 -> V_30 -> V_41 ( & V_35 , & V_33 ) ;
F_21 ( V_36 == - V_40 ) ;
if ( V_36 > 0 )
* V_34 = V_35 . V_38 ;
return V_36 ;
}
T_2 F_37 ( struct V_1 * V_1 , const char T_4 * V_67 , T_3 V_44 ,
T_1 * V_45 )
{
if ( V_1 -> V_30 -> V_68 )
return V_1 -> V_30 -> V_68 ( V_1 , V_67 , V_44 , V_45 ) ;
else if ( V_1 -> V_30 -> V_41 )
return F_36 ( V_1 , V_67 , V_44 , V_45 ) ;
else
return - V_6 ;
}
T_2 F_38 ( struct V_1 * V_1 , const char * V_53 , T_3 V_44 , T_1 * V_45 )
{
T_5 V_69 ;
const char T_4 * V_67 ;
T_2 V_36 ;
if ( ! ( V_1 -> V_2 & V_70 ) )
return - V_6 ;
V_69 = F_39 () ;
F_40 ( F_41 () ) ;
V_67 = ( V_71 const char T_4 * ) V_53 ;
if ( V_44 > V_65 )
V_44 = V_65 ;
V_36 = F_37 ( V_1 , V_67 , V_44 , V_45 ) ;
F_40 ( V_69 ) ;
if ( V_36 > 0 ) {
F_42 ( V_1 ) ;
F_43 ( V_66 , V_36 ) ;
}
F_44 ( V_66 ) ;
return V_36 ;
}
T_2 F_45 ( struct V_1 * V_1 , const char T_4 * V_53 , T_3 V_44 , T_1 * V_45 )
{
T_2 V_36 ;
if ( ! ( V_1 -> V_2 & V_72 ) )
return - V_61 ;
if ( ! ( V_1 -> V_2 & V_70 ) )
return - V_6 ;
if ( F_24 ( ! F_32 ( V_73 , V_53 , V_44 ) ) )
return - V_64 ;
V_36 = F_23 ( V_42 , V_1 , V_45 , V_44 ) ;
if ( ! V_36 ) {
if ( V_44 > V_65 )
V_44 = V_65 ;
F_46 ( V_1 ) ;
V_36 = F_37 ( V_1 , V_53 , V_44 , V_45 ) ;
if ( V_36 > 0 ) {
F_42 ( V_1 ) ;
F_43 ( V_66 , V_36 ) ;
}
F_44 ( V_66 ) ;
F_47 ( V_1 ) ;
}
return V_36 ;
}
static inline T_1 F_48 ( struct V_1 * V_1 )
{
return V_1 -> V_7 ;
}
static inline void F_49 ( struct V_1 * V_1 , T_1 V_45 )
{
V_1 -> V_7 = V_45 ;
}
unsigned long F_50 ( struct V_55 * V_56 , unsigned long V_74 , T_3 V_75 )
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
static T_2 F_51 ( struct V_1 * V_52 , struct V_32 * V_33 ,
T_1 * V_34 , T_6 F_18 , int V_77 )
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
V_36 = F_18 ( & V_35 , V_33 ) ;
F_21 ( V_36 == - V_40 ) ;
* V_34 = V_35 . V_38 ;
return V_36 ;
}
static T_2 F_52 ( struct V_1 * V_52 , struct V_32 * V_33 ,
T_1 * V_34 , T_7 F_18 , int V_77 )
{
T_2 V_36 = 0 ;
if ( V_77 & ~ V_78 )
return - V_81 ;
while ( F_53 ( V_33 ) ) {
struct V_55 V_55 = F_54 ( V_33 ) ;
T_2 V_86 ;
V_86 = F_18 ( V_52 , V_55 . V_57 , V_55 . V_58 , V_34 ) ;
if ( V_86 < 0 ) {
if ( ! V_36 )
V_36 = V_86 ;
break;
}
V_36 += V_86 ;
if ( V_86 != V_55 . V_58 )
break;
F_55 ( V_33 , V_86 ) ;
}
return V_36 ;
}
T_2 F_56 ( int type , const struct V_55 T_4 * V_87 ,
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
V_56 = F_57 ( V_74 * sizeof( struct V_55 ) , V_92 ) ;
if ( V_56 == NULL ) {
V_36 = - V_93 ;
goto V_27;
}
}
if ( F_58 ( V_56 , V_87 , V_74 * sizeof( * V_87 ) ) ) {
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
&& F_24 ( ! F_32 ( F_59 ( type ) , V_53 , V_54 ) ) ) {
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
static T_2 F_60 ( int type , struct V_1 * V_1 ,
const struct V_55 T_4 * V_87 ,
unsigned long V_74 , T_1 * V_45 ,
int V_77 )
{
T_3 V_94 ;
struct V_55 V_95 [ V_96 ] ;
struct V_55 * V_56 = V_95 ;
struct V_32 V_33 ;
T_2 V_36 ;
T_7 F_18 ;
T_6 V_97 ;
V_36 = F_61 ( type , V_87 , V_74 ,
F_62 ( V_95 ) , & V_56 , & V_33 ) ;
if ( V_36 < 0 )
return V_36 ;
V_94 = F_53 ( & V_33 ) ;
if ( ! V_94 )
goto V_27;
V_36 = F_23 ( type , V_1 , V_45 , V_94 ) ;
if ( V_36 < 0 )
goto V_27;
if ( type == V_39 ) {
F_18 = V_1 -> V_30 -> V_59 ;
V_97 = V_1 -> V_30 -> V_37 ;
} else {
F_18 = ( T_7 ) V_1 -> V_30 -> V_68 ;
V_97 = V_1 -> V_30 -> V_41 ;
F_46 ( V_1 ) ;
}
if ( V_97 )
V_36 = F_51 ( V_1 , & V_33 , V_45 , V_97 , V_77 ) ;
else
V_36 = F_52 ( V_1 , & V_33 , V_45 , F_18 , V_77 ) ;
if ( type != V_39 )
F_47 ( V_1 ) ;
V_27:
F_63 ( V_56 ) ;
if ( ( V_36 + ( type == V_39 ) ) > 0 ) {
if ( type == V_39 )
F_33 ( V_1 ) ;
else
F_42 ( V_1 ) ;
}
return V_36 ;
}
T_2 F_64 ( struct V_1 * V_1 , const struct V_55 T_4 * V_98 ,
unsigned long V_99 , T_1 * V_45 , int V_77 )
{
if ( ! ( V_1 -> V_2 & V_60 ) )
return - V_61 ;
if ( ! ( V_1 -> V_2 & V_62 ) )
return - V_6 ;
return F_60 ( V_39 , V_1 , V_98 , V_99 , V_45 , V_77 ) ;
}
T_2 F_65 ( struct V_1 * V_1 , const struct V_55 T_4 * V_98 ,
unsigned long V_99 , T_1 * V_45 , int V_77 )
{
if ( ! ( V_1 -> V_2 & V_72 ) )
return - V_61 ;
if ( ! ( V_1 -> V_2 & V_70 ) )
return - V_6 ;
return F_60 ( V_42 , V_1 , V_98 , V_99 , V_45 , V_77 ) ;
}
static T_2 F_66 ( unsigned long V_100 , const struct V_55 T_4 * V_98 ,
unsigned long V_99 , int V_77 )
{
struct V_100 V_101 = F_67 ( V_100 ) ;
T_2 V_36 = - V_61 ;
if ( V_101 . V_1 ) {
T_1 V_45 = F_48 ( V_101 . V_1 ) ;
V_36 = F_64 ( V_101 . V_1 , V_98 , V_99 , & V_45 , V_77 ) ;
if ( V_36 >= 0 )
F_49 ( V_101 . V_1 , V_45 ) ;
F_68 ( V_101 ) ;
}
if ( V_36 > 0 )
F_34 ( V_66 , V_36 ) ;
F_35 ( V_66 ) ;
return V_36 ;
}
static T_2 F_69 ( unsigned long V_100 , const struct V_55 T_4 * V_98 ,
unsigned long V_99 , int V_77 )
{
struct V_100 V_101 = F_67 ( V_100 ) ;
T_2 V_36 = - V_61 ;
if ( V_101 . V_1 ) {
T_1 V_45 = F_48 ( V_101 . V_1 ) ;
V_36 = F_65 ( V_101 . V_1 , V_98 , V_99 , & V_45 , V_77 ) ;
if ( V_36 >= 0 )
F_49 ( V_101 . V_1 , V_45 ) ;
F_68 ( V_101 ) ;
}
if ( V_36 > 0 )
F_43 ( V_66 , V_36 ) ;
F_44 ( V_66 ) ;
return V_36 ;
}
static inline T_1 F_70 ( unsigned long V_102 , unsigned long V_103 )
{
#define F_71 (BITS_PER_LONG / 2)
return ( ( ( T_1 ) V_102 << F_71 ) << F_71 ) | V_103 ;
}
static T_2 F_72 ( unsigned long V_100 , const struct V_55 T_4 * V_98 ,
unsigned long V_99 , T_1 V_45 , int V_77 )
{
struct V_100 V_101 ;
T_2 V_36 = - V_61 ;
if ( V_45 < 0 )
return - V_6 ;
V_101 = F_73 ( V_100 ) ;
if ( V_101 . V_1 ) {
V_36 = - V_25 ;
if ( V_101 . V_1 -> V_2 & V_104 )
V_36 = F_64 ( V_101 . V_1 , V_98 , V_99 , & V_45 , V_77 ) ;
F_74 ( V_101 ) ;
}
if ( V_36 > 0 )
F_34 ( V_66 , V_36 ) ;
F_35 ( V_66 ) ;
return V_36 ;
}
static T_2 F_75 ( unsigned long V_100 , const struct V_55 T_4 * V_98 ,
unsigned long V_99 , T_1 V_45 , int V_77 )
{
struct V_100 V_101 ;
T_2 V_36 = - V_61 ;
if ( V_45 < 0 )
return - V_6 ;
V_101 = F_73 ( V_100 ) ;
if ( V_101 . V_1 ) {
V_36 = - V_25 ;
if ( V_101 . V_1 -> V_2 & V_105 )
V_36 = F_65 ( V_101 . V_1 , V_98 , V_99 , & V_45 , V_77 ) ;
F_74 ( V_101 ) ;
}
if ( V_36 > 0 )
F_43 ( V_66 , V_36 ) ;
F_44 ( V_66 ) ;
return V_36 ;
}
static T_2 F_76 ( int type , struct V_1 * V_1 ,
const struct V_106 T_4 * V_87 ,
unsigned long V_74 , T_1 * V_45 ,
int V_77 )
{
T_8 V_94 ;
struct V_55 V_95 [ V_96 ] ;
struct V_55 * V_56 = V_95 ;
struct V_32 V_33 ;
T_2 V_36 ;
T_7 F_18 ;
T_6 V_97 ;
V_36 = F_77 ( type , V_87 , V_74 ,
V_96 , & V_56 , & V_33 ) ;
if ( V_36 < 0 )
return V_36 ;
V_94 = F_53 ( & V_33 ) ;
if ( ! V_94 )
goto V_27;
V_36 = F_23 ( type , V_1 , V_45 , V_94 ) ;
if ( V_36 < 0 )
goto V_27;
if ( type == V_39 ) {
F_18 = V_1 -> V_30 -> V_59 ;
V_97 = V_1 -> V_30 -> V_37 ;
} else {
F_18 = ( T_7 ) V_1 -> V_30 -> V_68 ;
V_97 = V_1 -> V_30 -> V_41 ;
F_46 ( V_1 ) ;
}
if ( V_97 )
V_36 = F_51 ( V_1 , & V_33 , V_45 , V_97 , V_77 ) ;
else
V_36 = F_52 ( V_1 , & V_33 , V_45 , F_18 , V_77 ) ;
if ( type != V_39 )
F_47 ( V_1 ) ;
V_27:
F_63 ( V_56 ) ;
if ( ( V_36 + ( type == V_39 ) ) > 0 ) {
if ( type == V_39 )
F_33 ( V_1 ) ;
else
F_42 ( V_1 ) ;
}
return V_36 ;
}
static T_3 F_78 ( struct V_1 * V_1 ,
const struct V_106 T_4 * V_98 ,
unsigned long V_99 , T_1 * V_45 , int V_77 )
{
T_2 V_36 = - V_61 ;
if ( ! ( V_1 -> V_2 & V_60 ) )
goto V_27;
V_36 = - V_6 ;
if ( ! ( V_1 -> V_2 & V_62 ) )
goto V_27;
V_36 = F_76 ( V_39 , V_1 , V_98 , V_99 , V_45 , V_77 ) ;
V_27:
if ( V_36 > 0 )
F_34 ( V_66 , V_36 ) ;
F_35 ( V_66 ) ;
return V_36 ;
}
static T_3 F_79 ( T_9 V_100 ,
const struct V_106 T_4 * V_98 ,
T_9 V_99 , int V_77 )
{
struct V_100 V_101 = F_67 ( V_100 ) ;
T_2 V_36 ;
T_1 V_45 ;
if ( ! V_101 . V_1 )
return - V_61 ;
V_45 = V_101 . V_1 -> V_7 ;
V_36 = F_78 ( V_101 . V_1 , V_98 , V_99 , & V_45 , V_77 ) ;
if ( V_36 >= 0 )
V_101 . V_1 -> V_7 = V_45 ;
F_68 ( V_101 ) ;
return V_36 ;
}
static long F_80 ( unsigned long V_100 ,
const struct V_106 T_4 * V_98 ,
unsigned long V_99 , T_1 V_45 , int V_77 )
{
struct V_100 V_101 ;
T_2 V_36 ;
if ( V_45 < 0 )
return - V_6 ;
V_101 = F_73 ( V_100 ) ;
if ( ! V_101 . V_1 )
return - V_61 ;
V_36 = - V_25 ;
if ( V_101 . V_1 -> V_2 & V_104 )
V_36 = F_78 ( V_101 . V_1 , V_98 , V_99 , & V_45 , V_77 ) ;
F_74 ( V_101 ) ;
return V_36 ;
}
static T_3 F_81 ( struct V_1 * V_1 ,
const struct V_106 T_4 * V_98 ,
unsigned long V_99 , T_1 * V_45 , int V_77 )
{
T_2 V_36 = - V_61 ;
if ( ! ( V_1 -> V_2 & V_72 ) )
goto V_27;
V_36 = - V_6 ;
if ( ! ( V_1 -> V_2 & V_70 ) )
goto V_27;
V_36 = F_76 ( V_42 , V_1 , V_98 , V_99 , V_45 , 0 ) ;
V_27:
if ( V_36 > 0 )
F_43 ( V_66 , V_36 ) ;
F_44 ( V_66 ) ;
return V_36 ;
}
static T_3 F_82 ( T_9 V_100 ,
const struct V_106 T_4 * V_98 ,
T_9 V_99 , int V_77 )
{
struct V_100 V_101 = F_67 ( V_100 ) ;
T_2 V_36 ;
T_1 V_45 ;
if ( ! V_101 . V_1 )
return - V_61 ;
V_45 = V_101 . V_1 -> V_7 ;
V_36 = F_81 ( V_101 . V_1 , V_98 , V_99 , & V_45 , V_77 ) ;
if ( V_36 >= 0 )
V_101 . V_1 -> V_7 = V_45 ;
F_68 ( V_101 ) ;
return V_36 ;
}
static long F_83 ( unsigned long V_100 ,
const struct V_106 T_4 * V_98 ,
unsigned long V_99 , T_1 V_45 , int V_77 )
{
struct V_100 V_101 ;
T_2 V_36 ;
if ( V_45 < 0 )
return - V_6 ;
V_101 = F_73 ( V_100 ) ;
if ( ! V_101 . V_1 )
return - V_61 ;
V_36 = - V_25 ;
if ( V_101 . V_1 -> V_2 & V_105 )
V_36 = F_81 ( V_101 . V_1 , V_98 , V_99 , & V_45 , V_77 ) ;
F_74 ( V_101 ) ;
return V_36 ;
}
static T_2 F_84 ( int V_107 , int V_108 , T_1 * V_34 ,
T_3 V_44 , T_1 V_109 )
{
struct V_100 V_110 , V_27 ;
struct V_17 * V_111 , * V_112 ;
T_1 V_45 ;
T_1 V_113 ;
T_2 V_26 ;
int V_114 ;
V_26 = - V_61 ;
V_110 = F_73 ( V_108 ) ;
if ( ! V_110 . V_1 )
goto V_27;
if ( ! ( V_110 . V_1 -> V_2 & V_60 ) )
goto V_115;
V_26 = - V_25 ;
if ( ! V_34 ) {
V_45 = V_110 . V_1 -> V_7 ;
} else {
V_45 = * V_34 ;
if ( ! ( V_110 . V_1 -> V_2 & V_104 ) )
goto V_115;
}
V_26 = F_23 ( V_39 , V_110 . V_1 , & V_45 , V_44 ) ;
if ( V_26 < 0 )
goto V_115;
if ( V_44 > V_65 )
V_44 = V_65 ;
V_26 = - V_61 ;
V_27 = F_73 ( V_107 ) ;
if ( ! V_27 . V_1 )
goto V_115;
if ( ! ( V_27 . V_1 -> V_2 & V_72 ) )
goto V_116;
V_26 = - V_6 ;
V_111 = F_14 ( V_110 . V_1 ) ;
V_112 = F_14 ( V_27 . V_1 ) ;
V_113 = V_27 . V_1 -> V_7 ;
V_26 = F_23 ( V_42 , V_27 . V_1 , & V_113 , V_44 ) ;
if ( V_26 < 0 )
goto V_116;
if ( ! V_109 )
V_109 = F_85 ( V_111 -> V_20 -> V_21 , V_112 -> V_20 -> V_21 ) ;
if ( F_24 ( V_45 + V_44 > V_109 ) ) {
V_26 = - V_46 ;
if ( V_45 >= V_109 )
goto V_116;
V_44 = V_109 - V_45 ;
}
V_114 = 0 ;
#if 0
if (in.file->f_flags & O_NONBLOCK)
fl = SPLICE_F_NONBLOCK;
#endif
F_46 ( V_27 . V_1 ) ;
V_26 = F_86 ( V_110 . V_1 , & V_45 , V_27 . V_1 , & V_113 , V_44 , V_114 ) ;
F_47 ( V_27 . V_1 ) ;
if ( V_26 > 0 ) {
F_34 ( V_66 , V_26 ) ;
F_43 ( V_66 , V_26 ) ;
F_33 ( V_110 . V_1 ) ;
F_42 ( V_27 . V_1 ) ;
V_27 . V_1 -> V_7 = V_113 ;
if ( V_34 )
* V_34 = V_45 ;
else
V_110 . V_1 -> V_7 = V_45 ;
}
F_35 ( V_66 ) ;
F_44 ( V_66 ) ;
if ( V_45 > V_109 )
V_26 = - V_46 ;
V_116:
F_74 ( V_27 ) ;
V_115:
F_74 ( V_110 ) ;
V_27:
return V_26 ;
}
T_2 F_87 ( struct V_1 * V_117 , T_1 V_118 ,
struct V_1 * V_119 , T_1 V_120 ,
T_3 V_54 , unsigned int V_77 )
{
struct V_17 * V_121 = F_14 ( V_117 ) ;
struct V_17 * V_122 = F_14 ( V_119 ) ;
T_2 V_36 ;
if ( V_77 != 0 )
return - V_6 ;
V_36 = F_23 ( V_39 , V_117 , & V_118 , V_54 ) ;
if ( F_24 ( V_36 ) )
return V_36 ;
V_36 = F_23 ( V_42 , V_119 , & V_120 , V_54 ) ;
if ( F_24 ( V_36 ) )
return V_36 ;
if ( ! ( V_117 -> V_2 & V_60 ) ||
! ( V_119 -> V_2 & V_72 ) ||
( V_119 -> V_123 & V_124 ) )
return - V_61 ;
if ( V_121 -> V_20 != V_122 -> V_20 )
return - V_125 ;
if ( V_54 == 0 )
return 0 ;
F_88 ( V_122 -> V_20 ) ;
if ( V_117 -> V_30 -> V_126 ) {
V_36 = V_117 -> V_30 -> V_126 ( V_117 , V_118 ,
V_119 , V_120 , V_54 ) ;
if ( V_36 == 0 ) {
V_36 = V_54 ;
goto V_127;
}
}
if ( V_119 -> V_30 -> V_128 ) {
V_36 = V_119 -> V_30 -> V_128 ( V_117 , V_118 , V_119 ,
V_120 , V_54 , V_77 ) ;
if ( V_36 != - V_81 )
goto V_127;
}
V_36 = F_86 ( V_117 , & V_118 , V_119 , & V_120 ,
V_54 > V_65 ? V_65 : V_54 , 0 ) ;
V_127:
if ( V_36 > 0 ) {
F_33 ( V_117 ) ;
F_34 ( V_66 , V_36 ) ;
F_42 ( V_119 ) ;
F_43 ( V_66 , V_36 ) ;
}
F_35 ( V_66 ) ;
F_44 ( V_66 ) ;
F_89 ( V_122 -> V_20 ) ;
return V_36 ;
}
static int F_90 ( struct V_1 * V_1 , T_1 V_45 , T_10 V_54 , bool V_68 )
{
struct V_17 * V_17 = F_14 ( V_1 ) ;
if ( F_24 ( V_45 < 0 ) )
return - V_6 ;
if ( F_24 ( ( T_1 ) ( V_45 + V_54 ) < 0 ) )
return - V_6 ;
if ( F_24 ( V_17 -> V_47 && F_25 ( V_17 ) ) ) {
T_1 V_129 = V_54 ? V_45 + V_54 - 1 : V_24 ;
int V_26 ;
V_26 = F_26 ( V_17 , V_1 , V_45 , V_129 ,
V_68 ? V_49 : V_48 ) ;
if ( V_26 < 0 )
return V_26 ;
}
return F_27 ( V_1 , V_68 ? V_51 : V_50 ) ;
}
int F_91 ( struct V_17 * V_121 , T_1 V_118 ,
struct V_17 * V_122 , T_1 V_120 ,
T_10 * V_54 , bool V_130 )
{
T_1 V_131 = V_122 -> V_20 -> V_132 ;
T_1 V_133 ;
T_1 V_134 ;
bool V_135 = ( V_121 == V_122 ) ;
int V_36 ;
if ( F_92 ( V_122 ) )
return - V_136 ;
if ( F_93 ( V_121 ) || F_93 ( V_122 ) )
return - V_137 ;
if ( F_94 ( V_121 -> V_138 ) || F_94 ( V_122 -> V_138 ) )
return - V_139 ;
if ( ! F_95 ( V_121 -> V_138 ) || ! F_95 ( V_122 -> V_138 ) )
return - V_6 ;
V_134 = F_7 ( V_121 ) ;
if ( V_134 == 0 )
return 0 ;
if ( * V_54 == 0 ) {
if ( V_130 || V_118 == V_134 )
return 0 ;
if ( V_118 > V_134 )
return - V_6 ;
* V_54 = V_134 - V_118 ;
}
if ( V_118 + * V_54 < V_118 || V_120 + * V_54 < V_120 ||
V_118 + * V_54 > V_134 )
return - V_6 ;
if ( V_130 ) {
T_1 V_140 ;
V_140 = F_7 ( V_122 ) ;
if ( V_120 >= V_140 || V_120 + * V_54 > V_140 )
return - V_6 ;
}
if ( V_118 + * V_54 == V_134 )
V_133 = F_96 ( V_134 , V_131 ) - V_118 ;
else
V_133 = * V_54 ;
if ( ! F_97 ( V_118 , V_131 ) || ! F_97 ( V_118 + V_133 , V_131 ) ||
! F_97 ( V_120 , V_131 ) || ! F_97 ( V_120 + V_133 , V_131 ) )
return - V_6 ;
if ( V_135 ) {
if ( V_120 + V_133 > V_118 && V_120 < V_118 + V_133 )
return - V_6 ;
}
F_98 ( V_121 ) ;
if ( ! V_135 )
F_98 ( V_122 ) ;
V_36 = F_99 ( V_121 -> V_141 ,
V_118 , V_118 + * V_54 - 1 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_99 ( V_122 -> V_141 ,
V_120 , V_120 + * V_54 - 1 ) ;
if ( V_36 )
return V_36 ;
if ( V_130 ) {
bool V_142 = false ;
V_36 = F_100 ( V_121 , V_118 ,
V_122 , V_120 , * V_54 , & V_142 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_142 )
return - V_143 ;
}
return 1 ;
}
int F_101 ( struct V_1 * V_117 , T_1 V_118 ,
struct V_1 * V_119 , T_1 V_120 , T_10 V_54 )
{
struct V_17 * V_121 = F_14 ( V_117 ) ;
struct V_17 * V_122 = F_14 ( V_119 ) ;
int V_36 ;
if ( F_94 ( V_121 -> V_138 ) || F_94 ( V_122 -> V_138 ) )
return - V_139 ;
if ( ! F_95 ( V_121 -> V_138 ) || ! F_95 ( V_122 -> V_138 ) )
return - V_6 ;
if ( V_121 -> V_20 != V_122 -> V_20 )
return - V_125 ;
if ( ! ( V_117 -> V_2 & V_60 ) ||
! ( V_119 -> V_2 & V_72 ) ||
( V_119 -> V_123 & V_124 ) )
return - V_61 ;
if ( ! V_117 -> V_30 -> V_126 )
return - V_81 ;
V_36 = F_90 ( V_117 , V_118 , V_54 , false ) ;
if ( V_36 )
return V_36 ;
V_36 = F_90 ( V_119 , V_120 , V_54 , true ) ;
if ( V_36 )
return V_36 ;
if ( V_118 + V_54 > F_7 ( V_121 ) )
return - V_6 ;
V_36 = V_117 -> V_30 -> V_126 ( V_117 , V_118 ,
V_119 , V_120 , V_54 ) ;
if ( ! V_36 ) {
F_33 ( V_117 ) ;
F_42 ( V_119 ) ;
}
return V_36 ;
}
static struct V_144 * F_102 ( struct V_17 * V_17 , T_1 V_4 )
{
struct V_145 * V_146 ;
struct V_144 * V_144 ;
T_11 V_147 ;
V_147 = V_4 >> V_148 ;
V_146 = V_17 -> V_141 ;
V_144 = F_103 ( V_146 , V_147 , NULL ) ;
if ( F_104 ( V_144 ) )
return V_144 ;
if ( ! F_105 ( V_144 ) ) {
F_106 ( V_144 ) ;
return F_107 ( - V_149 ) ;
}
F_108 ( V_144 ) ;
return V_144 ;
}
int F_100 ( struct V_17 * V_150 , T_1 V_151 ,
struct V_17 * V_152 , T_1 V_153 ,
T_1 V_54 , bool * V_142 )
{
T_1 V_154 ;
T_1 V_155 ;
void * V_156 ;
void * V_157 ;
struct V_144 * V_158 ;
struct V_144 * V_159 ;
T_1 V_160 ;
bool V_161 ;
int error ;
error = - V_6 ;
V_161 = true ;
while ( V_54 ) {
V_154 = V_151 & ( V_162 - 1 ) ;
V_155 = V_153 & ( V_162 - 1 ) ;
V_160 = F_85 ( V_162 - V_154 ,
V_162 - V_155 ) ;
V_160 = F_85 ( V_160 , V_54 ) ;
if ( V_160 <= 0 )
goto V_163;
V_158 = F_102 ( V_150 , V_151 ) ;
if ( F_104 ( V_158 ) ) {
error = F_109 ( V_158 ) ;
goto V_163;
}
V_159 = F_102 ( V_152 , V_153 ) ;
if ( F_104 ( V_159 ) ) {
error = F_109 ( V_159 ) ;
F_110 ( V_158 ) ;
F_106 ( V_158 ) ;
goto V_163;
}
V_156 = F_111 ( V_158 ) ;
V_157 = F_111 ( V_159 ) ;
F_112 ( V_158 ) ;
F_112 ( V_159 ) ;
if ( memcmp ( V_156 + V_154 , V_157 + V_155 , V_160 ) )
V_161 = false ;
F_113 ( V_157 ) ;
F_113 ( V_156 ) ;
F_110 ( V_159 ) ;
F_110 ( V_158 ) ;
F_106 ( V_159 ) ;
F_106 ( V_158 ) ;
if ( ! V_161 )
break;
V_151 += V_160 ;
V_153 += V_160 ;
V_54 -= V_160 ;
}
* V_142 = V_161 ;
return 0 ;
V_163:
return error ;
}
int F_114 ( struct V_1 * V_1 , struct V_164 * V_161 )
{
struct V_165 * V_166 ;
struct V_17 * V_150 = F_14 ( V_1 ) ;
T_10 V_167 ;
T_10 V_54 ;
int V_168 ;
int V_36 ;
bool V_169 = F_115 ( V_170 ) ;
T_12 V_44 = V_161 -> V_171 ;
struct V_1 * V_172 ;
T_1 V_173 ;
T_2 V_174 ;
if ( ! ( V_1 -> V_2 & V_60 ) )
return - V_6 ;
if ( V_161 -> V_175 || V_161 -> V_176 )
return - V_6 ;
V_167 = V_161 -> V_177 ;
V_54 = V_161 -> V_178 ;
V_36 = - V_139 ;
if ( F_94 ( V_150 -> V_138 ) )
goto V_27;
V_36 = - V_6 ;
if ( ! F_95 ( V_150 -> V_138 ) )
goto V_27;
V_36 = F_90 ( V_1 , V_167 , V_54 , false ) ;
if ( V_36 < 0 )
goto V_27;
V_36 = 0 ;
if ( V_167 + V_54 > F_7 ( V_150 ) )
return - V_6 ;
for ( V_168 = 0 ; V_168 < V_44 ; V_168 ++ ) {
V_161 -> V_166 [ V_168 ] . V_179 = 0ULL ;
V_161 -> V_166 [ V_168 ] . V_180 = V_181 ;
}
for ( V_168 = 0 , V_166 = V_161 -> V_166 ; V_168 < V_44 ; V_168 ++ , V_166 ++ ) {
struct V_17 * V_182 ;
struct V_100 V_183 = F_73 ( V_166 -> V_184 ) ;
V_172 = V_183 . V_1 ;
if ( ! V_172 ) {
V_166 -> V_180 = - V_61 ;
goto V_185;
}
V_182 = F_14 ( V_172 ) ;
V_36 = F_116 ( V_172 ) ;
if ( V_36 ) {
V_166 -> V_180 = V_36 ;
goto V_185;
}
V_173 = V_166 -> V_186 ;
V_36 = F_90 ( V_172 , V_173 , V_54 , true ) ;
if ( V_36 < 0 ) {
V_166 -> V_180 = V_36 ;
goto V_187;
}
V_36 = 0 ;
if ( V_166 -> V_188 ) {
V_166 -> V_180 = - V_6 ;
} else if ( ! ( V_169 || ( V_172 -> V_2 & V_72 ) ) ) {
V_166 -> V_180 = - V_6 ;
} else if ( V_1 -> V_189 . V_190 != V_172 -> V_189 . V_190 ) {
V_166 -> V_180 = - V_125 ;
} else if ( F_94 ( V_182 -> V_138 ) ) {
V_166 -> V_180 = - V_139 ;
} else if ( V_172 -> V_30 -> V_191 == NULL ) {
V_166 -> V_180 = - V_6 ;
} else {
V_174 = V_172 -> V_30 -> V_191 ( V_1 , V_167 ,
V_54 , V_172 ,
V_166 -> V_186 ) ;
if ( V_174 == - V_143 )
V_166 -> V_180 = V_192 ;
else if ( V_174 < 0 )
V_166 -> V_180 = V_174 ;
else
V_166 -> V_179 += V_174 ;
}
V_187:
F_117 ( V_172 ) ;
V_185:
F_74 ( V_183 ) ;
if ( F_118 ( V_66 ) )
goto V_27;
}
V_27:
return V_36 ;
}
