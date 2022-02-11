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
T_2 F_62 ( int type ,
const struct V_94 T_4 * V_87 , unsigned long V_74 ,
unsigned long V_88 , struct V_55 * V_89 ,
struct V_55 * * V_90 )
{
T_6 V_95 ;
struct V_55 * V_56 = * V_90 = V_89 ;
T_2 V_36 = 0 ;
int V_76 ;
if ( V_74 == 0 )
goto V_27;
V_36 = - V_6 ;
if ( V_74 > V_91 )
goto V_27;
if ( V_74 > V_88 ) {
V_36 = - V_93 ;
V_56 = F_59 ( V_74 * sizeof( struct V_55 ) , V_92 ) ;
if ( V_56 == NULL )
goto V_27;
}
* V_90 = V_56 ;
V_36 = - V_64 ;
if ( ! F_34 ( V_73 , V_87 , V_74 * sizeof( * V_87 ) ) )
goto V_27;
V_95 = 0 ;
V_36 = - V_6 ;
for ( V_76 = 0 ; V_76 < V_74 ; V_76 ++ ) {
T_7 V_53 ;
T_6 V_54 ;
if ( F_63 ( V_54 , & V_87 -> V_58 ) ||
F_63 ( V_53 , & V_87 -> V_57 ) ) {
V_36 = - V_64 ;
goto V_27;
}
if ( V_54 < 0 )
goto V_27;
if ( type >= 0 &&
! F_34 ( F_61 ( type ) , F_64 ( V_53 ) , V_54 ) ) {
V_36 = - V_64 ;
goto V_27;
}
if ( V_54 > V_65 - V_95 )
V_54 = V_65 - V_95 ;
V_95 += V_54 ;
V_56 -> V_57 = F_64 ( V_53 ) ;
V_56 -> V_58 = ( V_96 ) V_54 ;
V_87 ++ ;
V_56 ++ ;
}
V_36 = V_95 ;
V_27:
return V_36 ;
}
static T_2 F_65 ( int type , struct V_1 * V_1 ,
struct V_32 * V_33 , T_1 * V_45 , int V_77 )
{
T_3 V_95 ;
T_2 V_36 = 0 ;
V_95 = F_55 ( V_33 ) ;
if ( ! V_95 )
goto V_27;
V_36 = F_25 ( type , V_1 , V_45 , V_95 ) ;
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
static T_2 F_66 ( int type , struct V_1 * V_1 ,
const struct V_55 T_4 * V_87 ,
unsigned long V_74 , T_1 * V_45 ,
int V_77 )
{
struct V_55 V_97 [ V_98 ] ;
struct V_55 * V_56 = V_97 ;
struct V_32 V_33 ;
T_2 V_36 ;
V_36 = F_67 ( type , V_87 , V_74 ,
F_68 ( V_97 ) , & V_56 , & V_33 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_65 ( type , V_1 , & V_33 , V_45 , V_77 ) ;
F_69 ( V_56 ) ;
return V_36 ;
}
T_2 F_70 ( struct V_1 * V_1 , const struct V_55 T_4 * V_99 ,
unsigned long V_100 , T_1 * V_45 , int V_77 )
{
if ( ! ( V_1 -> V_2 & V_60 ) )
return - V_61 ;
if ( ! ( V_1 -> V_2 & V_62 ) )
return - V_6 ;
return F_66 ( V_39 , V_1 , V_99 , V_100 , V_45 , V_77 ) ;
}
T_2 F_71 ( struct V_1 * V_1 , const struct V_55 T_4 * V_99 ,
unsigned long V_100 , T_1 * V_45 , int V_77 )
{
if ( ! ( V_1 -> V_2 & V_72 ) )
return - V_61 ;
if ( ! ( V_1 -> V_2 & V_70 ) )
return - V_6 ;
return F_66 ( V_42 , V_1 , V_99 , V_100 , V_45 , V_77 ) ;
}
static T_2 F_72 ( unsigned long V_101 , const struct V_55 T_4 * V_99 ,
unsigned long V_100 , int V_77 )
{
struct V_101 V_102 = F_73 ( V_101 ) ;
T_2 V_36 = - V_61 ;
if ( V_102 . V_1 ) {
T_1 V_45 = F_50 ( V_102 . V_1 ) ;
V_36 = F_70 ( V_102 . V_1 , V_99 , V_100 , & V_45 , V_77 ) ;
if ( V_36 >= 0 )
F_51 ( V_102 . V_1 , V_45 ) ;
F_74 ( V_102 ) ;
}
if ( V_36 > 0 )
F_36 ( V_66 , V_36 ) ;
F_37 ( V_66 ) ;
return V_36 ;
}
static T_2 F_75 ( unsigned long V_101 , const struct V_55 T_4 * V_99 ,
unsigned long V_100 , int V_77 )
{
struct V_101 V_102 = F_73 ( V_101 ) ;
T_2 V_36 = - V_61 ;
if ( V_102 . V_1 ) {
T_1 V_45 = F_50 ( V_102 . V_1 ) ;
V_36 = F_71 ( V_102 . V_1 , V_99 , V_100 , & V_45 , V_77 ) ;
if ( V_36 >= 0 )
F_51 ( V_102 . V_1 , V_45 ) ;
F_74 ( V_102 ) ;
}
if ( V_36 > 0 )
F_45 ( V_66 , V_36 ) ;
F_46 ( V_66 ) ;
return V_36 ;
}
static inline T_1 F_76 ( unsigned long V_103 , unsigned long V_104 )
{
#define F_77 (BITS_PER_LONG / 2)
return ( ( ( T_1 ) V_103 << F_77 ) << F_77 ) | V_104 ;
}
static T_2 F_78 ( unsigned long V_101 , const struct V_55 T_4 * V_99 ,
unsigned long V_100 , T_1 V_45 , int V_77 )
{
struct V_101 V_102 ;
T_2 V_36 = - V_61 ;
if ( V_45 < 0 )
return - V_6 ;
V_102 = F_79 ( V_101 ) ;
if ( V_102 . V_1 ) {
V_36 = - V_25 ;
if ( V_102 . V_1 -> V_2 & V_105 )
V_36 = F_70 ( V_102 . V_1 , V_99 , V_100 , & V_45 , V_77 ) ;
F_80 ( V_102 ) ;
}
if ( V_36 > 0 )
F_36 ( V_66 , V_36 ) ;
F_37 ( V_66 ) ;
return V_36 ;
}
static T_2 F_81 ( unsigned long V_101 , const struct V_55 T_4 * V_99 ,
unsigned long V_100 , T_1 V_45 , int V_77 )
{
struct V_101 V_102 ;
T_2 V_36 = - V_61 ;
if ( V_45 < 0 )
return - V_6 ;
V_102 = F_79 ( V_101 ) ;
if ( V_102 . V_1 ) {
V_36 = - V_25 ;
if ( V_102 . V_1 -> V_2 & V_106 )
V_36 = F_71 ( V_102 . V_1 , V_99 , V_100 , & V_45 , V_77 ) ;
F_80 ( V_102 ) ;
}
if ( V_36 > 0 )
F_45 ( V_66 , V_36 ) ;
F_46 ( V_66 ) ;
return V_36 ;
}
static T_2 F_82 ( int type , struct V_1 * V_1 ,
const struct V_94 T_4 * V_87 ,
unsigned long V_74 , T_1 * V_45 ,
int V_77 )
{
struct V_55 V_97 [ V_98 ] ;
struct V_55 * V_56 = V_97 ;
struct V_32 V_33 ;
T_2 V_36 ;
V_36 = F_83 ( type , V_87 , V_74 ,
V_98 , & V_56 , & V_33 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_65 ( type , V_1 , & V_33 , V_45 , V_77 ) ;
F_69 ( V_56 ) ;
return V_36 ;
}
static T_3 F_84 ( struct V_1 * V_1 ,
const struct V_94 T_4 * V_99 ,
unsigned long V_100 , T_1 * V_45 , int V_77 )
{
T_2 V_36 = - V_61 ;
if ( ! ( V_1 -> V_2 & V_60 ) )
goto V_27;
V_36 = - V_6 ;
if ( ! ( V_1 -> V_2 & V_62 ) )
goto V_27;
V_36 = F_82 ( V_39 , V_1 , V_99 , V_100 , V_45 , V_77 ) ;
V_27:
if ( V_36 > 0 )
F_36 ( V_66 , V_36 ) ;
F_37 ( V_66 ) ;
return V_36 ;
}
static T_3 F_85 ( T_8 V_101 ,
const struct V_94 T_4 * V_99 ,
T_8 V_100 , int V_77 )
{
struct V_101 V_102 = F_73 ( V_101 ) ;
T_2 V_36 ;
T_1 V_45 ;
if ( ! V_102 . V_1 )
return - V_61 ;
V_45 = V_102 . V_1 -> V_7 ;
V_36 = F_84 ( V_102 . V_1 , V_99 , V_100 , & V_45 , V_77 ) ;
if ( V_36 >= 0 )
V_102 . V_1 -> V_7 = V_45 ;
F_74 ( V_102 ) ;
return V_36 ;
}
static long F_86 ( unsigned long V_101 ,
const struct V_94 T_4 * V_99 ,
unsigned long V_100 , T_1 V_45 , int V_77 )
{
struct V_101 V_102 ;
T_2 V_36 ;
if ( V_45 < 0 )
return - V_6 ;
V_102 = F_79 ( V_101 ) ;
if ( ! V_102 . V_1 )
return - V_61 ;
V_36 = - V_25 ;
if ( V_102 . V_1 -> V_2 & V_105 )
V_36 = F_84 ( V_102 . V_1 , V_99 , V_100 , & V_45 , V_77 ) ;
F_80 ( V_102 ) ;
return V_36 ;
}
static T_3 F_87 ( struct V_1 * V_1 ,
const struct V_94 T_4 * V_99 ,
unsigned long V_100 , T_1 * V_45 , int V_77 )
{
T_2 V_36 = - V_61 ;
if ( ! ( V_1 -> V_2 & V_72 ) )
goto V_27;
V_36 = - V_6 ;
if ( ! ( V_1 -> V_2 & V_70 ) )
goto V_27;
V_36 = F_82 ( V_42 , V_1 , V_99 , V_100 , V_45 , V_77 ) ;
V_27:
if ( V_36 > 0 )
F_45 ( V_66 , V_36 ) ;
F_46 ( V_66 ) ;
return V_36 ;
}
static T_3 F_88 ( T_8 V_101 ,
const struct V_94 T_4 * V_99 ,
T_8 V_100 , int V_77 )
{
struct V_101 V_102 = F_73 ( V_101 ) ;
T_2 V_36 ;
T_1 V_45 ;
if ( ! V_102 . V_1 )
return - V_61 ;
V_45 = V_102 . V_1 -> V_7 ;
V_36 = F_87 ( V_102 . V_1 , V_99 , V_100 , & V_45 , V_77 ) ;
if ( V_36 >= 0 )
V_102 . V_1 -> V_7 = V_45 ;
F_74 ( V_102 ) ;
return V_36 ;
}
static long F_89 ( unsigned long V_101 ,
const struct V_94 T_4 * V_99 ,
unsigned long V_100 , T_1 V_45 , int V_77 )
{
struct V_101 V_102 ;
T_2 V_36 ;
if ( V_45 < 0 )
return - V_6 ;
V_102 = F_79 ( V_101 ) ;
if ( ! V_102 . V_1 )
return - V_61 ;
V_36 = - V_25 ;
if ( V_102 . V_1 -> V_2 & V_106 )
V_36 = F_87 ( V_102 . V_1 , V_99 , V_100 , & V_45 , V_77 ) ;
F_80 ( V_102 ) ;
return V_36 ;
}
static T_2 F_90 ( int V_107 , int V_108 , T_1 * V_34 ,
T_3 V_44 , T_1 V_109 )
{
struct V_101 V_110 , V_27 ;
struct V_17 * V_111 , * V_112 ;
T_1 V_45 ;
T_1 V_113 ;
T_2 V_26 ;
int V_114 ;
V_26 = - V_61 ;
V_110 = F_79 ( V_108 ) ;
if ( ! V_110 . V_1 )
goto V_27;
if ( ! ( V_110 . V_1 -> V_2 & V_60 ) )
goto V_115;
V_26 = - V_25 ;
if ( ! V_34 ) {
V_45 = V_110 . V_1 -> V_7 ;
} else {
V_45 = * V_34 ;
if ( ! ( V_110 . V_1 -> V_2 & V_105 ) )
goto V_115;
}
V_26 = F_25 ( V_39 , V_110 . V_1 , & V_45 , V_44 ) ;
if ( V_26 < 0 )
goto V_115;
if ( V_44 > V_65 )
V_44 = V_65 ;
V_26 = - V_61 ;
V_27 = F_79 ( V_107 ) ;
if ( ! V_27 . V_1 )
goto V_115;
if ( ! ( V_27 . V_1 -> V_2 & V_72 ) )
goto V_116;
V_26 = - V_6 ;
V_111 = F_14 ( V_110 . V_1 ) ;
V_112 = F_14 ( V_27 . V_1 ) ;
V_113 = V_27 . V_1 -> V_7 ;
V_26 = F_25 ( V_42 , V_27 . V_1 , & V_113 , V_44 ) ;
if ( V_26 < 0 )
goto V_116;
if ( ! V_109 )
V_109 = F_91 ( V_111 -> V_20 -> V_21 , V_112 -> V_20 -> V_21 ) ;
if ( F_26 ( V_45 + V_44 > V_109 ) ) {
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
F_48 ( V_27 . V_1 ) ;
V_26 = F_92 ( V_110 . V_1 , & V_45 , V_27 . V_1 , & V_113 , V_44 , V_114 ) ;
F_49 ( V_27 . V_1 ) ;
if ( V_26 > 0 ) {
F_36 ( V_66 , V_26 ) ;
F_45 ( V_66 , V_26 ) ;
F_35 ( V_110 . V_1 ) ;
F_44 ( V_27 . V_1 ) ;
V_27 . V_1 -> V_7 = V_113 ;
if ( V_34 )
* V_34 = V_45 ;
else
V_110 . V_1 -> V_7 = V_45 ;
}
F_37 ( V_66 ) ;
F_46 ( V_66 ) ;
if ( V_45 > V_109 )
V_26 = - V_46 ;
V_116:
F_80 ( V_27 ) ;
V_115:
F_80 ( V_110 ) ;
V_27:
return V_26 ;
}
T_2 F_93 ( struct V_1 * V_117 , T_1 V_118 ,
struct V_1 * V_119 , T_1 V_120 ,
T_3 V_54 , unsigned int V_77 )
{
struct V_17 * V_121 = F_14 ( V_117 ) ;
struct V_17 * V_122 = F_14 ( V_119 ) ;
T_2 V_36 ;
if ( V_77 != 0 )
return - V_6 ;
if ( F_94 ( V_121 -> V_123 ) || F_94 ( V_122 -> V_123 ) )
return - V_124 ;
if ( ! F_95 ( V_121 -> V_123 ) || ! F_95 ( V_122 -> V_123 ) )
return - V_6 ;
V_36 = F_25 ( V_39 , V_117 , & V_118 , V_54 ) ;
if ( F_26 ( V_36 ) )
return V_36 ;
V_36 = F_25 ( V_42 , V_119 , & V_120 , V_54 ) ;
if ( F_26 ( V_36 ) )
return V_36 ;
if ( ! ( V_117 -> V_2 & V_60 ) ||
! ( V_119 -> V_2 & V_72 ) ||
( V_119 -> V_125 & V_126 ) )
return - V_61 ;
if ( V_121 -> V_20 != V_122 -> V_20 )
return - V_127 ;
if ( V_54 == 0 )
return 0 ;
F_48 ( V_119 ) ;
if ( V_117 -> V_30 -> V_128 ) {
V_36 = V_117 -> V_30 -> V_128 ( V_117 , V_118 ,
V_119 , V_120 , V_54 ) ;
if ( V_36 == 0 ) {
V_36 = V_54 ;
goto V_129;
}
}
if ( V_119 -> V_30 -> V_130 ) {
V_36 = V_119 -> V_30 -> V_130 ( V_117 , V_118 , V_119 ,
V_120 , V_54 , V_77 ) ;
if ( V_36 != - V_81 )
goto V_129;
}
V_36 = F_92 ( V_117 , & V_118 , V_119 , & V_120 ,
V_54 > V_65 ? V_65 : V_54 , 0 ) ;
V_129:
if ( V_36 > 0 ) {
F_35 ( V_117 ) ;
F_36 ( V_66 , V_36 ) ;
F_44 ( V_119 ) ;
F_45 ( V_66 , V_36 ) ;
}
F_37 ( V_66 ) ;
F_46 ( V_66 ) ;
F_49 ( V_119 ) ;
return V_36 ;
}
static int F_96 ( struct V_1 * V_1 , T_1 V_45 , T_9 V_54 , bool V_68 )
{
struct V_17 * V_17 = F_14 ( V_1 ) ;
if ( F_26 ( V_45 < 0 ) )
return - V_6 ;
if ( F_26 ( ( T_1 ) ( V_45 + V_54 ) < 0 ) )
return - V_6 ;
if ( F_26 ( V_17 -> V_47 && F_27 ( V_17 ) ) ) {
T_1 V_131 = V_54 ? V_45 + V_54 - 1 : V_24 ;
int V_26 ;
V_26 = F_28 ( V_17 , V_1 , V_45 , V_131 ,
V_68 ? V_49 : V_48 ) ;
if ( V_26 < 0 )
return V_26 ;
}
return F_29 ( V_1 , V_68 ? V_51 : V_50 ) ;
}
int F_97 ( struct V_17 * V_121 , T_1 V_118 ,
struct V_17 * V_122 , T_1 V_120 ,
T_9 * V_54 , bool V_132 )
{
T_1 V_133 = V_122 -> V_20 -> V_134 ;
T_1 V_135 ;
T_1 V_136 ;
bool V_137 = ( V_121 == V_122 ) ;
int V_36 ;
if ( F_98 ( V_122 ) )
return - V_138 ;
if ( F_99 ( V_121 ) || F_99 ( V_122 ) )
return - V_139 ;
if ( F_94 ( V_121 -> V_123 ) || F_94 ( V_122 -> V_123 ) )
return - V_124 ;
if ( ! F_95 ( V_121 -> V_123 ) || ! F_95 ( V_122 -> V_123 ) )
return - V_6 ;
V_136 = F_7 ( V_121 ) ;
if ( V_136 == 0 )
return 0 ;
if ( * V_54 == 0 ) {
if ( V_132 || V_118 == V_136 )
return 0 ;
if ( V_118 > V_136 )
return - V_6 ;
* V_54 = V_136 - V_118 ;
}
if ( V_118 + * V_54 < V_118 || V_120 + * V_54 < V_120 ||
V_118 + * V_54 > V_136 )
return - V_6 ;
if ( V_132 ) {
T_1 V_140 ;
V_140 = F_7 ( V_122 ) ;
if ( V_120 >= V_140 || V_120 + * V_54 > V_140 )
return - V_6 ;
}
if ( V_118 + * V_54 == V_136 )
V_135 = F_100 ( V_136 , V_133 ) - V_118 ;
else
V_135 = * V_54 ;
if ( ! F_101 ( V_118 , V_133 ) || ! F_101 ( V_118 + V_135 , V_133 ) ||
! F_101 ( V_120 , V_133 ) || ! F_101 ( V_120 + V_135 , V_133 ) )
return - V_6 ;
if ( V_137 ) {
if ( V_120 + V_135 > V_118 && V_120 < V_118 + V_135 )
return - V_6 ;
}
F_102 ( V_121 ) ;
if ( ! V_137 )
F_102 ( V_122 ) ;
V_36 = F_103 ( V_121 -> V_141 ,
V_118 , V_118 + * V_54 - 1 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_103 ( V_122 -> V_141 ,
V_120 , V_120 + * V_54 - 1 ) ;
if ( V_36 )
return V_36 ;
if ( V_132 ) {
bool V_142 = false ;
V_36 = F_104 ( V_121 , V_118 ,
V_122 , V_120 , * V_54 , & V_142 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_142 )
return - V_143 ;
}
return 1 ;
}
int F_105 ( struct V_1 * V_117 , T_1 V_118 ,
struct V_1 * V_119 , T_1 V_120 , T_9 V_54 )
{
struct V_17 * V_121 = F_14 ( V_117 ) ;
struct V_17 * V_122 = F_14 ( V_119 ) ;
int V_36 ;
if ( F_94 ( V_121 -> V_123 ) || F_94 ( V_122 -> V_123 ) )
return - V_124 ;
if ( ! F_95 ( V_121 -> V_123 ) || ! F_95 ( V_122 -> V_123 ) )
return - V_6 ;
if ( V_121 -> V_20 != V_122 -> V_20 )
return - V_127 ;
if ( ! ( V_117 -> V_2 & V_60 ) ||
! ( V_119 -> V_2 & V_72 ) ||
( V_119 -> V_125 & V_126 ) )
return - V_61 ;
if ( ! V_117 -> V_30 -> V_128 )
return - V_81 ;
V_36 = F_96 ( V_117 , V_118 , V_54 , false ) ;
if ( V_36 )
return V_36 ;
V_36 = F_96 ( V_119 , V_120 , V_54 , true ) ;
if ( V_36 )
return V_36 ;
if ( V_118 + V_54 > F_7 ( V_121 ) )
return - V_6 ;
V_36 = V_117 -> V_30 -> V_128 ( V_117 , V_118 ,
V_119 , V_120 , V_54 ) ;
if ( ! V_36 ) {
F_35 ( V_117 ) ;
F_44 ( V_119 ) ;
}
return V_36 ;
}
static struct V_144 * F_106 ( struct V_17 * V_17 , T_1 V_4 )
{
struct V_145 * V_146 ;
struct V_144 * V_144 ;
T_10 V_147 ;
V_147 = V_4 >> V_148 ;
V_146 = V_17 -> V_141 ;
V_144 = F_107 ( V_146 , V_147 , NULL ) ;
if ( F_108 ( V_144 ) )
return V_144 ;
if ( ! F_109 ( V_144 ) ) {
F_110 ( V_144 ) ;
return F_111 ( - V_149 ) ;
}
F_112 ( V_144 ) ;
return V_144 ;
}
int F_104 ( struct V_17 * V_150 , T_1 V_151 ,
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
V_160 = F_91 ( V_162 - V_154 ,
V_162 - V_155 ) ;
V_160 = F_91 ( V_160 , V_54 ) ;
if ( V_160 <= 0 )
goto V_163;
V_158 = F_106 ( V_150 , V_151 ) ;
if ( F_108 ( V_158 ) ) {
error = F_113 ( V_158 ) ;
goto V_163;
}
V_159 = F_106 ( V_152 , V_153 ) ;
if ( F_108 ( V_159 ) ) {
error = F_113 ( V_159 ) ;
F_114 ( V_158 ) ;
F_110 ( V_158 ) ;
goto V_163;
}
V_156 = F_115 ( V_158 ) ;
V_157 = F_115 ( V_159 ) ;
F_116 ( V_158 ) ;
F_116 ( V_159 ) ;
if ( memcmp ( V_156 + V_154 , V_157 + V_155 , V_160 ) )
V_161 = false ;
F_117 ( V_157 ) ;
F_117 ( V_156 ) ;
F_114 ( V_159 ) ;
F_114 ( V_158 ) ;
F_110 ( V_159 ) ;
F_110 ( V_158 ) ;
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
int F_118 ( struct V_1 * V_1 , struct V_164 * V_161 )
{
struct V_165 * V_166 ;
struct V_17 * V_150 = F_14 ( V_1 ) ;
T_9 V_167 ;
T_9 V_54 ;
int V_168 ;
int V_36 ;
bool V_169 = F_119 ( V_170 ) ;
T_11 V_44 = V_161 -> V_171 ;
struct V_1 * V_172 ;
T_1 V_173 ;
T_2 V_174 ;
if ( ! ( V_1 -> V_2 & V_60 ) )
return - V_6 ;
if ( V_161 -> V_175 || V_161 -> V_176 )
return - V_6 ;
V_167 = V_161 -> V_177 ;
V_54 = V_161 -> V_178 ;
V_36 = - V_124 ;
if ( F_94 ( V_150 -> V_123 ) )
goto V_27;
V_36 = - V_6 ;
if ( ! F_95 ( V_150 -> V_123 ) )
goto V_27;
V_36 = F_96 ( V_1 , V_167 , V_54 , false ) ;
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
struct V_101 V_183 = F_79 ( V_166 -> V_184 ) ;
V_172 = V_183 . V_1 ;
if ( ! V_172 ) {
V_166 -> V_180 = - V_61 ;
goto V_185;
}
V_182 = F_14 ( V_172 ) ;
V_36 = F_120 ( V_172 ) ;
if ( V_36 ) {
V_166 -> V_180 = V_36 ;
goto V_185;
}
V_173 = V_166 -> V_186 ;
V_36 = F_96 ( V_172 , V_173 , V_54 , true ) ;
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
V_166 -> V_180 = - V_127 ;
} else if ( F_94 ( V_182 -> V_123 ) ) {
V_166 -> V_180 = - V_124 ;
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
F_121 ( V_172 ) ;
V_185:
F_80 ( V_183 ) ;
if ( F_122 ( V_66 ) )
goto V_27;
}
V_27:
return V_36 ;
}
