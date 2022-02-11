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
static inline struct V_32 F_19 ( int V_32 )
{
return F_20 ( F_21 ( V_32 ) ) ;
}
static inline void F_22 ( struct V_32 V_33 )
{
if ( V_33 . V_34 & V_35 )
F_23 ( & V_33 . V_1 -> V_36 ) ;
F_24 ( V_33 ) ;
}
T_2 F_25 ( struct V_1 * V_1 , struct V_37 * V_38 , T_1 * V_39 )
{
struct V_40 V_40 ;
T_2 V_41 ;
if ( ! V_1 -> V_30 -> V_42 )
return - V_6 ;
F_26 ( & V_40 , V_1 ) ;
V_40 . V_43 = * V_39 ;
V_38 -> type |= V_44 ;
V_41 = V_1 -> V_30 -> V_42 ( & V_40 , V_38 ) ;
F_27 ( V_41 == - V_45 ) ;
if ( V_41 > 0 )
* V_39 = V_40 . V_43 ;
return V_41 ;
}
T_2 F_28 ( struct V_1 * V_1 , struct V_37 * V_38 , T_1 * V_39 )
{
struct V_40 V_40 ;
T_2 V_41 ;
if ( ! V_1 -> V_30 -> V_46 )
return - V_6 ;
F_26 ( & V_40 , V_1 ) ;
V_40 . V_43 = * V_39 ;
V_38 -> type |= V_47 ;
V_41 = V_1 -> V_30 -> V_46 ( & V_40 , V_38 ) ;
F_27 ( V_41 == - V_45 ) ;
if ( V_41 > 0 )
* V_39 = V_40 . V_43 ;
return V_41 ;
}
int F_29 ( int V_48 , struct V_1 * V_1 , const T_1 * V_39 , T_3 V_49 )
{
struct V_17 * V_17 ;
T_1 V_50 ;
int V_26 = - V_6 ;
V_17 = F_14 ( V_1 ) ;
if ( F_30 ( ( T_2 ) V_49 < 0 ) )
return V_26 ;
V_50 = * V_39 ;
if ( F_30 ( V_50 < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_26 ;
if ( V_49 >= - V_50 )
return - V_51 ;
} else if ( F_30 ( ( T_1 ) ( V_50 + V_49 ) < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_26 ;
}
if ( F_30 ( V_17 -> V_52 && F_31 ( V_17 ) ) ) {
V_26 = F_32 ( V_17 , V_1 , V_50 , V_50 + V_49 - 1 ,
V_48 == V_44 ? V_53 : V_54 ) ;
if ( V_26 < 0 )
return V_26 ;
}
V_26 = F_33 ( V_1 ,
V_48 == V_44 ? V_55 : V_56 ) ;
if ( V_26 )
return V_26 ;
return V_49 > V_57 ? V_57 : V_49 ;
}
static T_2 F_34 ( struct V_1 * V_58 , char T_4 * V_59 , T_3 V_60 , T_1 * V_39 )
{
struct V_61 V_62 = { . V_63 = V_59 , . V_64 = V_60 } ;
struct V_40 V_40 ;
struct V_37 V_38 ;
T_2 V_41 ;
F_26 ( & V_40 , V_58 ) ;
V_40 . V_43 = * V_39 ;
F_35 ( & V_38 , V_44 , & V_62 , 1 , V_60 ) ;
V_41 = V_58 -> V_30 -> V_42 ( & V_40 , & V_38 ) ;
F_27 ( V_41 == - V_45 ) ;
* V_39 = V_40 . V_43 ;
return V_41 ;
}
T_2 F_36 ( struct V_1 * V_1 , char T_4 * V_59 , T_3 V_49 ,
T_1 * V_50 )
{
if ( V_1 -> V_30 -> V_65 )
return V_1 -> V_30 -> V_65 ( V_1 , V_59 , V_49 , V_50 ) ;
else if ( V_1 -> V_30 -> V_42 )
return F_34 ( V_1 , V_59 , V_49 , V_50 ) ;
else
return - V_6 ;
}
T_2 F_37 ( struct V_1 * V_1 , char T_4 * V_59 , T_3 V_49 , T_1 * V_50 )
{
T_2 V_41 ;
if ( ! ( V_1 -> V_2 & V_66 ) )
return - V_67 ;
if ( ! ( V_1 -> V_2 & V_68 ) )
return - V_6 ;
if ( F_30 ( ! F_38 ( V_69 , V_59 , V_49 ) ) )
return - V_70 ;
V_41 = F_29 ( V_44 , V_1 , V_50 , V_49 ) ;
if ( V_41 >= 0 ) {
V_49 = V_41 ;
V_41 = F_36 ( V_1 , V_59 , V_49 , V_50 ) ;
if ( V_41 > 0 ) {
F_39 ( V_1 ) ;
F_40 ( V_71 , V_41 ) ;
}
F_41 ( V_71 ) ;
}
return V_41 ;
}
static T_2 F_42 ( struct V_1 * V_58 , const char T_4 * V_59 , T_3 V_60 , T_1 * V_39 )
{
struct V_61 V_62 = { . V_63 = ( void T_4 * ) V_59 , . V_64 = V_60 } ;
struct V_40 V_40 ;
struct V_37 V_38 ;
T_2 V_41 ;
F_26 ( & V_40 , V_58 ) ;
V_40 . V_43 = * V_39 ;
F_35 ( & V_38 , V_47 , & V_62 , 1 , V_60 ) ;
V_41 = V_58 -> V_30 -> V_46 ( & V_40 , & V_38 ) ;
F_27 ( V_41 == - V_45 ) ;
if ( V_41 > 0 )
* V_39 = V_40 . V_43 ;
return V_41 ;
}
T_2 F_43 ( struct V_1 * V_1 , const char T_4 * V_72 , T_3 V_49 ,
T_1 * V_50 )
{
if ( V_1 -> V_30 -> V_73 )
return V_1 -> V_30 -> V_73 ( V_1 , V_72 , V_49 , V_50 ) ;
else if ( V_1 -> V_30 -> V_46 )
return F_42 ( V_1 , V_72 , V_49 , V_50 ) ;
else
return - V_6 ;
}
T_2 F_44 ( struct V_1 * V_1 , const char * V_59 , T_3 V_49 , T_1 * V_50 )
{
T_5 V_74 ;
const char T_4 * V_72 ;
T_2 V_41 ;
if ( ! ( V_1 -> V_2 & V_75 ) )
return - V_6 ;
V_74 = F_45 () ;
F_46 ( F_47 () ) ;
V_72 = ( V_76 const char T_4 * ) V_59 ;
if ( V_49 > V_57 )
V_49 = V_57 ;
V_41 = F_43 ( V_1 , V_72 , V_49 , V_50 ) ;
F_46 ( V_74 ) ;
if ( V_41 > 0 ) {
F_48 ( V_1 ) ;
F_49 ( V_71 , V_41 ) ;
}
F_50 ( V_71 ) ;
return V_41 ;
}
T_2 F_51 ( struct V_1 * V_1 , const char T_4 * V_59 , T_3 V_49 , T_1 * V_50 )
{
T_2 V_41 ;
if ( ! ( V_1 -> V_2 & V_77 ) )
return - V_67 ;
if ( ! ( V_1 -> V_2 & V_75 ) )
return - V_6 ;
if ( F_30 ( ! F_38 ( V_78 , V_59 , V_49 ) ) )
return - V_70 ;
V_41 = F_29 ( V_47 , V_1 , V_50 , V_49 ) ;
if ( V_41 >= 0 ) {
V_49 = V_41 ;
F_52 ( V_1 ) ;
V_41 = F_43 ( V_1 , V_59 , V_49 , V_50 ) ;
if ( V_41 > 0 ) {
F_48 ( V_1 ) ;
F_49 ( V_71 , V_41 ) ;
}
F_50 ( V_71 ) ;
F_53 ( V_1 ) ;
}
return V_41 ;
}
static inline T_1 F_54 ( struct V_1 * V_1 )
{
return V_1 -> V_7 ;
}
static inline void F_55 ( struct V_1 * V_1 , T_1 V_50 )
{
V_1 -> V_7 = V_50 ;
}
unsigned long F_56 ( struct V_61 * V_62 , unsigned long V_79 , T_3 V_80 )
{
unsigned long V_81 = 0 ;
T_3 V_60 = 0 ;
while ( V_81 < V_79 ) {
V_81 ++ ;
if ( V_60 + V_62 -> V_64 >= V_80 ) {
V_62 -> V_64 = V_80 - V_60 ;
break;
}
V_60 += V_62 -> V_64 ;
V_62 ++ ;
}
return V_81 ;
}
static T_2 F_57 ( struct V_1 * V_58 , struct V_37 * V_38 ,
T_1 * V_39 , T_6 F_18 , int V_34 )
{
struct V_40 V_40 ;
T_2 V_41 ;
if ( V_34 & ~ V_82 )
return - V_83 ;
F_26 ( & V_40 , V_58 ) ;
if ( V_34 & V_82 )
V_40 . V_84 |= V_85 ;
V_40 . V_43 = * V_39 ;
V_41 = F_18 ( & V_40 , V_38 ) ;
F_27 ( V_41 == - V_45 ) ;
* V_39 = V_40 . V_43 ;
return V_41 ;
}
static T_2 F_58 ( struct V_1 * V_58 , struct V_37 * V_38 ,
T_1 * V_39 , T_7 F_18 , int V_34 )
{
T_2 V_41 = 0 ;
if ( V_34 & ~ V_82 )
return - V_83 ;
while ( F_59 ( V_38 ) ) {
struct V_61 V_61 = F_60 ( V_38 ) ;
T_2 V_86 ;
V_86 = F_18 ( V_58 , V_61 . V_63 , V_61 . V_64 , V_39 ) ;
if ( V_86 < 0 ) {
if ( ! V_41 )
V_41 = V_86 ;
break;
}
V_41 += V_86 ;
if ( V_86 != V_61 . V_64 )
break;
F_61 ( V_38 , V_86 ) ;
}
return V_41 ;
}
T_2 F_62 ( int type , const struct V_61 T_4 * V_87 ,
unsigned long V_79 , unsigned long V_88 ,
struct V_61 * V_89 ,
struct V_61 * * V_90 )
{
unsigned long V_81 ;
T_2 V_41 ;
struct V_61 * V_62 = V_89 ;
if ( V_79 == 0 ) {
V_41 = 0 ;
goto V_27;
}
if ( V_79 > V_91 ) {
V_41 = - V_6 ;
goto V_27;
}
if ( V_79 > V_88 ) {
V_62 = F_63 ( V_79 * sizeof( struct V_61 ) , V_92 ) ;
if ( V_62 == NULL ) {
V_41 = - V_93 ;
goto V_27;
}
}
if ( F_64 ( V_62 , V_87 , V_79 * sizeof( * V_87 ) ) ) {
V_41 = - V_70 ;
goto V_27;
}
V_41 = 0 ;
for ( V_81 = 0 ; V_81 < V_79 ; V_81 ++ ) {
void T_4 * V_59 = V_62 [ V_81 ] . V_63 ;
T_2 V_60 = ( T_2 ) V_62 [ V_81 ] . V_64 ;
if ( V_60 < 0 ) {
V_41 = - V_6 ;
goto V_27;
}
if ( type >= 0
&& F_30 ( ! F_38 ( F_65 ( type ) , V_59 , V_60 ) ) ) {
V_41 = - V_70 ;
goto V_27;
}
if ( V_60 > V_57 - V_41 ) {
V_60 = V_57 - V_41 ;
V_62 [ V_81 ] . V_64 = V_60 ;
}
V_41 += V_60 ;
}
V_27:
* V_90 = V_62 ;
return V_41 ;
}
static T_2 F_66 ( int type , struct V_1 * V_1 ,
const struct V_61 T_4 * V_87 ,
unsigned long V_79 , T_1 * V_50 ,
int V_34 )
{
T_3 V_94 ;
struct V_61 V_95 [ V_96 ] ;
struct V_61 * V_62 = V_95 ;
struct V_37 V_38 ;
T_2 V_41 ;
T_7 F_18 ;
T_6 V_97 ;
V_41 = F_67 ( type , V_87 , V_79 ,
F_68 ( V_95 ) , & V_62 , & V_38 ) ;
if ( V_41 < 0 )
return V_41 ;
V_94 = F_59 ( & V_38 ) ;
if ( ! V_94 )
goto V_27;
V_41 = F_29 ( type , V_1 , V_50 , V_94 ) ;
if ( V_41 < 0 )
goto V_27;
if ( type == V_44 ) {
F_18 = V_1 -> V_30 -> V_65 ;
V_97 = V_1 -> V_30 -> V_42 ;
} else {
F_18 = ( T_7 ) V_1 -> V_30 -> V_73 ;
V_97 = V_1 -> V_30 -> V_46 ;
F_52 ( V_1 ) ;
}
if ( V_97 )
V_41 = F_57 ( V_1 , & V_38 , V_50 , V_97 , V_34 ) ;
else
V_41 = F_58 ( V_1 , & V_38 , V_50 , F_18 , V_34 ) ;
if ( type != V_44 )
F_53 ( V_1 ) ;
V_27:
F_69 ( V_62 ) ;
if ( ( V_41 + ( type == V_44 ) ) > 0 ) {
if ( type == V_44 )
F_39 ( V_1 ) ;
else
F_48 ( V_1 ) ;
}
return V_41 ;
}
T_2 F_70 ( struct V_1 * V_1 , const struct V_61 T_4 * V_98 ,
unsigned long V_99 , T_1 * V_50 , int V_34 )
{
if ( ! ( V_1 -> V_2 & V_66 ) )
return - V_67 ;
if ( ! ( V_1 -> V_2 & V_68 ) )
return - V_6 ;
return F_66 ( V_44 , V_1 , V_98 , V_99 , V_50 , V_34 ) ;
}
T_2 F_71 ( struct V_1 * V_1 , const struct V_61 T_4 * V_98 ,
unsigned long V_99 , T_1 * V_50 , int V_34 )
{
if ( ! ( V_1 -> V_2 & V_77 ) )
return - V_67 ;
if ( ! ( V_1 -> V_2 & V_75 ) )
return - V_6 ;
return F_66 ( V_47 , V_1 , V_98 , V_99 , V_50 , V_34 ) ;
}
static T_2 F_72 ( unsigned long V_32 , const struct V_61 T_4 * V_98 ,
unsigned long V_99 , int V_34 )
{
struct V_32 V_33 = F_19 ( V_32 ) ;
T_2 V_41 = - V_67 ;
if ( V_33 . V_1 ) {
T_1 V_50 = F_54 ( V_33 . V_1 ) ;
V_41 = F_70 ( V_33 . V_1 , V_98 , V_99 , & V_50 , V_34 ) ;
if ( V_41 >= 0 )
F_55 ( V_33 . V_1 , V_50 ) ;
F_22 ( V_33 ) ;
}
if ( V_41 > 0 )
F_40 ( V_71 , V_41 ) ;
F_41 ( V_71 ) ;
return V_41 ;
}
static T_2 F_73 ( unsigned long V_32 , const struct V_61 T_4 * V_98 ,
unsigned long V_99 , int V_34 )
{
struct V_32 V_33 = F_19 ( V_32 ) ;
T_2 V_41 = - V_67 ;
if ( V_33 . V_1 ) {
T_1 V_50 = F_54 ( V_33 . V_1 ) ;
V_41 = F_71 ( V_33 . V_1 , V_98 , V_99 , & V_50 , V_34 ) ;
if ( V_41 >= 0 )
F_55 ( V_33 . V_1 , V_50 ) ;
F_22 ( V_33 ) ;
}
if ( V_41 > 0 )
F_49 ( V_71 , V_41 ) ;
F_50 ( V_71 ) ;
return V_41 ;
}
static inline T_1 F_74 ( unsigned long V_100 , unsigned long V_101 )
{
#define F_75 (BITS_PER_LONG / 2)
return ( ( ( T_1 ) V_100 << F_75 ) << F_75 ) | V_101 ;
}
static T_2 F_76 ( unsigned long V_32 , const struct V_61 T_4 * V_98 ,
unsigned long V_99 , T_1 V_50 , int V_34 )
{
struct V_32 V_33 ;
T_2 V_41 = - V_67 ;
if ( V_50 < 0 )
return - V_6 ;
V_33 = F_77 ( V_32 ) ;
if ( V_33 . V_1 ) {
V_41 = - V_25 ;
if ( V_33 . V_1 -> V_2 & V_102 )
V_41 = F_70 ( V_33 . V_1 , V_98 , V_99 , & V_50 , V_34 ) ;
F_24 ( V_33 ) ;
}
if ( V_41 > 0 )
F_40 ( V_71 , V_41 ) ;
F_41 ( V_71 ) ;
return V_41 ;
}
static T_2 F_78 ( unsigned long V_32 , const struct V_61 T_4 * V_98 ,
unsigned long V_99 , T_1 V_50 , int V_34 )
{
struct V_32 V_33 ;
T_2 V_41 = - V_67 ;
if ( V_50 < 0 )
return - V_6 ;
V_33 = F_77 ( V_32 ) ;
if ( V_33 . V_1 ) {
V_41 = - V_25 ;
if ( V_33 . V_1 -> V_2 & V_103 )
V_41 = F_71 ( V_33 . V_1 , V_98 , V_99 , & V_50 , V_34 ) ;
F_24 ( V_33 ) ;
}
if ( V_41 > 0 )
F_49 ( V_71 , V_41 ) ;
F_50 ( V_71 ) ;
return V_41 ;
}
static T_2 F_79 ( int type , struct V_1 * V_1 ,
const struct V_104 T_4 * V_87 ,
unsigned long V_79 , T_1 * V_50 ,
int V_34 )
{
T_8 V_94 ;
struct V_61 V_95 [ V_96 ] ;
struct V_61 * V_62 = V_95 ;
struct V_37 V_38 ;
T_2 V_41 ;
T_7 F_18 ;
T_6 V_97 ;
V_41 = F_80 ( type , V_87 , V_79 ,
V_96 , & V_62 , & V_38 ) ;
if ( V_41 < 0 )
return V_41 ;
V_94 = F_59 ( & V_38 ) ;
if ( ! V_94 )
goto V_27;
V_41 = F_29 ( type , V_1 , V_50 , V_94 ) ;
if ( V_41 < 0 )
goto V_27;
if ( type == V_44 ) {
F_18 = V_1 -> V_30 -> V_65 ;
V_97 = V_1 -> V_30 -> V_42 ;
} else {
F_18 = ( T_7 ) V_1 -> V_30 -> V_73 ;
V_97 = V_1 -> V_30 -> V_46 ;
F_52 ( V_1 ) ;
}
if ( V_97 )
V_41 = F_57 ( V_1 , & V_38 , V_50 , V_97 , V_34 ) ;
else
V_41 = F_58 ( V_1 , & V_38 , V_50 , F_18 , V_34 ) ;
if ( type != V_44 )
F_53 ( V_1 ) ;
V_27:
F_69 ( V_62 ) ;
if ( ( V_41 + ( type == V_44 ) ) > 0 ) {
if ( type == V_44 )
F_39 ( V_1 ) ;
else
F_48 ( V_1 ) ;
}
return V_41 ;
}
static T_3 F_81 ( struct V_1 * V_1 ,
const struct V_104 T_4 * V_98 ,
unsigned long V_99 , T_1 * V_50 , int V_34 )
{
T_2 V_41 = - V_67 ;
if ( ! ( V_1 -> V_2 & V_66 ) )
goto V_27;
V_41 = - V_6 ;
if ( ! ( V_1 -> V_2 & V_68 ) )
goto V_27;
V_41 = F_79 ( V_44 , V_1 , V_98 , V_99 , V_50 , V_34 ) ;
V_27:
if ( V_41 > 0 )
F_40 ( V_71 , V_41 ) ;
F_41 ( V_71 ) ;
return V_41 ;
}
static T_3 F_82 ( T_9 V_32 ,
const struct V_104 T_4 * V_98 ,
T_9 V_99 , int V_34 )
{
struct V_32 V_33 = F_19 ( V_32 ) ;
T_2 V_41 ;
T_1 V_50 ;
if ( ! V_33 . V_1 )
return - V_67 ;
V_50 = V_33 . V_1 -> V_7 ;
V_41 = F_81 ( V_33 . V_1 , V_98 , V_99 , & V_50 , V_34 ) ;
if ( V_41 >= 0 )
V_33 . V_1 -> V_7 = V_50 ;
F_22 ( V_33 ) ;
return V_41 ;
}
static long F_83 ( unsigned long V_32 ,
const struct V_104 T_4 * V_98 ,
unsigned long V_99 , T_1 V_50 , int V_34 )
{
struct V_32 V_33 ;
T_2 V_41 ;
if ( V_50 < 0 )
return - V_6 ;
V_33 = F_77 ( V_32 ) ;
if ( ! V_33 . V_1 )
return - V_67 ;
V_41 = - V_25 ;
if ( V_33 . V_1 -> V_2 & V_102 )
V_41 = F_81 ( V_33 . V_1 , V_98 , V_99 , & V_50 , V_34 ) ;
F_24 ( V_33 ) ;
return V_41 ;
}
static T_3 F_84 ( struct V_1 * V_1 ,
const struct V_104 T_4 * V_98 ,
unsigned long V_99 , T_1 * V_50 , int V_34 )
{
T_2 V_41 = - V_67 ;
if ( ! ( V_1 -> V_2 & V_77 ) )
goto V_27;
V_41 = - V_6 ;
if ( ! ( V_1 -> V_2 & V_75 ) )
goto V_27;
V_41 = F_79 ( V_47 , V_1 , V_98 , V_99 , V_50 , 0 ) ;
V_27:
if ( V_41 > 0 )
F_49 ( V_71 , V_41 ) ;
F_50 ( V_71 ) ;
return V_41 ;
}
static T_3 F_85 ( T_9 V_32 ,
const struct V_104 T_4 * V_98 ,
T_9 V_99 , int V_34 )
{
struct V_32 V_33 = F_19 ( V_32 ) ;
T_2 V_41 ;
T_1 V_50 ;
if ( ! V_33 . V_1 )
return - V_67 ;
V_50 = V_33 . V_1 -> V_7 ;
V_41 = F_84 ( V_33 . V_1 , V_98 , V_99 , & V_50 , V_34 ) ;
if ( V_41 >= 0 )
V_33 . V_1 -> V_7 = V_50 ;
F_22 ( V_33 ) ;
return V_41 ;
}
static long F_86 ( unsigned long V_32 ,
const struct V_104 T_4 * V_98 ,
unsigned long V_99 , T_1 V_50 , int V_34 )
{
struct V_32 V_33 ;
T_2 V_41 ;
if ( V_50 < 0 )
return - V_6 ;
V_33 = F_77 ( V_32 ) ;
if ( ! V_33 . V_1 )
return - V_67 ;
V_41 = - V_25 ;
if ( V_33 . V_1 -> V_2 & V_103 )
V_41 = F_84 ( V_33 . V_1 , V_98 , V_99 , & V_50 , V_34 ) ;
F_24 ( V_33 ) ;
return V_41 ;
}
static T_2 F_87 ( int V_105 , int V_106 , T_1 * V_39 ,
T_3 V_49 , T_1 V_107 )
{
struct V_32 V_108 , V_27 ;
struct V_17 * V_109 , * V_110 ;
T_1 V_50 ;
T_1 V_111 ;
T_2 V_26 ;
int V_112 ;
V_26 = - V_67 ;
V_108 = F_77 ( V_106 ) ;
if ( ! V_108 . V_1 )
goto V_27;
if ( ! ( V_108 . V_1 -> V_2 & V_66 ) )
goto V_113;
V_26 = - V_25 ;
if ( ! V_39 ) {
V_50 = V_108 . V_1 -> V_7 ;
} else {
V_50 = * V_39 ;
if ( ! ( V_108 . V_1 -> V_2 & V_102 ) )
goto V_113;
}
V_26 = F_29 ( V_44 , V_108 . V_1 , & V_50 , V_49 ) ;
if ( V_26 < 0 )
goto V_113;
V_49 = V_26 ;
V_26 = - V_67 ;
V_27 = F_77 ( V_105 ) ;
if ( ! V_27 . V_1 )
goto V_113;
if ( ! ( V_27 . V_1 -> V_2 & V_77 ) )
goto V_114;
V_26 = - V_6 ;
V_109 = F_14 ( V_108 . V_1 ) ;
V_110 = F_14 ( V_27 . V_1 ) ;
V_111 = V_27 . V_1 -> V_7 ;
V_26 = F_29 ( V_47 , V_27 . V_1 , & V_111 , V_49 ) ;
if ( V_26 < 0 )
goto V_114;
V_49 = V_26 ;
if ( ! V_107 )
V_107 = F_88 ( V_109 -> V_20 -> V_21 , V_110 -> V_20 -> V_21 ) ;
if ( F_30 ( V_50 + V_49 > V_107 ) ) {
V_26 = - V_51 ;
if ( V_50 >= V_107 )
goto V_114;
V_49 = V_107 - V_50 ;
}
V_112 = 0 ;
#if 0
if (in.file->f_flags & O_NONBLOCK)
fl = SPLICE_F_NONBLOCK;
#endif
F_52 ( V_27 . V_1 ) ;
V_26 = F_89 ( V_108 . V_1 , & V_50 , V_27 . V_1 , & V_111 , V_49 , V_112 ) ;
F_53 ( V_27 . V_1 ) ;
if ( V_26 > 0 ) {
F_40 ( V_71 , V_26 ) ;
F_49 ( V_71 , V_26 ) ;
F_39 ( V_108 . V_1 ) ;
F_48 ( V_27 . V_1 ) ;
V_27 . V_1 -> V_7 = V_111 ;
if ( V_39 )
* V_39 = V_50 ;
else
V_108 . V_1 -> V_7 = V_50 ;
}
F_41 ( V_71 ) ;
F_50 ( V_71 ) ;
if ( V_50 > V_107 )
V_26 = - V_51 ;
V_114:
F_24 ( V_27 ) ;
V_113:
F_24 ( V_108 ) ;
V_27:
return V_26 ;
}
T_2 F_90 ( struct V_1 * V_115 , T_1 V_116 ,
struct V_1 * V_117 , T_1 V_118 ,
T_3 V_60 , unsigned int V_34 )
{
struct V_17 * V_119 = F_14 ( V_115 ) ;
struct V_17 * V_120 = F_14 ( V_117 ) ;
T_2 V_41 ;
if ( V_34 != 0 )
return - V_6 ;
V_41 = F_29 ( V_44 , V_115 , & V_116 , V_60 ) ;
if ( V_41 >= 0 )
V_41 = F_29 ( V_47 , V_117 , & V_118 , V_60 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( ! ( V_115 -> V_2 & V_66 ) ||
! ( V_117 -> V_2 & V_77 ) ||
( V_117 -> V_121 & V_122 ) )
return - V_67 ;
if ( V_119 -> V_20 != V_120 -> V_20 )
return - V_123 ;
if ( V_60 == 0 )
return 0 ;
V_41 = F_91 ( V_117 ) ;
if ( V_41 )
return V_41 ;
V_41 = - V_83 ;
if ( V_117 -> V_30 -> V_124 )
V_41 = V_117 -> V_30 -> V_124 ( V_115 , V_116 , V_117 ,
V_118 , V_60 , V_34 ) ;
if ( V_41 == - V_83 )
V_41 = F_89 ( V_115 , & V_116 , V_117 , & V_118 ,
V_60 > V_57 ? V_57 : V_60 , 0 ) ;
if ( V_41 > 0 ) {
F_39 ( V_115 ) ;
F_40 ( V_71 , V_41 ) ;
F_48 ( V_117 ) ;
F_49 ( V_71 , V_41 ) ;
}
F_41 ( V_71 ) ;
F_50 ( V_71 ) ;
F_92 ( V_117 ) ;
return V_41 ;
}
static int F_93 ( struct V_1 * V_1 , T_1 V_50 , T_10 V_60 , bool V_73 )
{
struct V_17 * V_17 = F_14 ( V_1 ) ;
if ( F_30 ( V_50 < 0 ) )
return - V_6 ;
if ( F_30 ( ( T_1 ) ( V_50 + V_60 ) < 0 ) )
return - V_6 ;
if ( F_30 ( V_17 -> V_52 && F_31 ( V_17 ) ) ) {
T_1 V_125 = V_60 ? V_50 + V_60 - 1 : V_24 ;
int V_26 ;
V_26 = F_32 ( V_17 , V_1 , V_50 , V_125 ,
V_73 ? V_54 : V_53 ) ;
if ( V_26 < 0 )
return V_26 ;
}
return F_33 ( V_1 , V_73 ? V_56 : V_55 ) ;
}
int F_94 ( struct V_1 * V_115 , T_1 V_116 ,
struct V_1 * V_117 , T_1 V_118 , T_10 V_60 )
{
struct V_17 * V_119 = F_14 ( V_115 ) ;
struct V_17 * V_120 = F_14 ( V_117 ) ;
int V_41 ;
if ( V_119 -> V_20 != V_120 -> V_20 ||
V_115 -> V_126 . V_127 != V_117 -> V_126 . V_127 )
return - V_123 ;
if ( F_95 ( V_119 -> V_128 ) || F_95 ( V_120 -> V_128 ) )
return - V_129 ;
if ( ! F_96 ( V_119 -> V_128 ) || ! F_96 ( V_120 -> V_128 ) )
return - V_6 ;
if ( ! ( V_115 -> V_2 & V_66 ) ||
! ( V_117 -> V_2 & V_77 ) ||
( V_117 -> V_121 & V_122 ) )
return - V_67 ;
if ( ! V_115 -> V_30 -> V_130 )
return - V_83 ;
V_41 = F_93 ( V_115 , V_116 , V_60 , false ) ;
if ( V_41 )
return V_41 ;
V_41 = F_93 ( V_117 , V_118 , V_60 , true ) ;
if ( V_41 )
return V_41 ;
if ( V_116 + V_60 > F_7 ( V_119 ) )
return - V_6 ;
V_41 = F_91 ( V_117 ) ;
if ( V_41 )
return V_41 ;
V_41 = V_115 -> V_30 -> V_130 ( V_115 , V_116 ,
V_117 , V_118 , V_60 ) ;
if ( ! V_41 ) {
F_39 ( V_115 ) ;
F_48 ( V_117 ) ;
}
F_92 ( V_117 ) ;
return V_41 ;
}
int F_97 ( struct V_1 * V_1 , struct V_131 * V_132 )
{
struct V_133 * V_134 ;
struct V_17 * V_135 = F_14 ( V_1 ) ;
T_10 V_136 ;
T_10 V_60 ;
int V_137 ;
int V_41 ;
bool V_138 = F_98 ( V_139 ) ;
T_11 V_49 = V_132 -> V_140 ;
struct V_1 * V_141 ;
T_1 V_142 ;
T_2 V_143 ;
if ( ! ( V_1 -> V_2 & V_66 ) )
return - V_6 ;
if ( V_132 -> V_144 || V_132 -> V_145 )
return - V_6 ;
V_136 = V_132 -> V_146 ;
V_60 = V_132 -> V_147 ;
V_41 = - V_129 ;
if ( F_95 ( V_135 -> V_128 ) )
goto V_27;
V_41 = - V_6 ;
if ( ! F_96 ( V_135 -> V_128 ) )
goto V_27;
V_41 = F_93 ( V_1 , V_136 , V_60 , false ) ;
if ( V_41 < 0 )
goto V_27;
V_41 = 0 ;
for ( V_137 = 0 ; V_137 < V_49 ; V_137 ++ ) {
V_132 -> V_134 [ V_137 ] . V_148 = 0ULL ;
V_132 -> V_134 [ V_137 ] . V_149 = V_150 ;
}
for ( V_137 = 0 , V_134 = V_132 -> V_134 ; V_137 < V_49 ; V_137 ++ , V_134 ++ ) {
struct V_17 * V_151 ;
struct V_32 V_152 = F_77 ( V_134 -> V_153 ) ;
V_141 = V_152 . V_1 ;
if ( ! V_141 ) {
V_134 -> V_149 = - V_67 ;
goto V_154;
}
V_151 = F_14 ( V_141 ) ;
V_41 = F_91 ( V_141 ) ;
if ( V_41 ) {
V_134 -> V_149 = V_41 ;
goto V_154;
}
V_142 = V_134 -> V_155 ;
V_41 = F_93 ( V_141 , V_142 , V_60 , true ) ;
if ( V_41 < 0 ) {
V_134 -> V_149 = V_41 ;
goto V_156;
}
V_41 = 0 ;
if ( V_134 -> V_157 ) {
V_134 -> V_149 = - V_6 ;
} else if ( ! ( V_138 || ( V_141 -> V_2 & V_77 ) ) ) {
V_134 -> V_149 = - V_6 ;
} else if ( V_1 -> V_126 . V_127 != V_141 -> V_126 . V_127 ) {
V_134 -> V_149 = - V_123 ;
} else if ( F_95 ( V_151 -> V_128 ) ) {
V_134 -> V_149 = - V_129 ;
} else if ( V_141 -> V_30 -> V_158 == NULL ) {
V_134 -> V_149 = - V_6 ;
} else {
V_143 = V_141 -> V_30 -> V_158 ( V_1 , V_136 ,
V_60 , V_141 ,
V_134 -> V_155 ) ;
if ( V_143 == - V_159 )
V_134 -> V_149 = V_160 ;
else if ( V_143 < 0 )
V_134 -> V_149 = V_143 ;
else
V_134 -> V_148 += V_143 ;
}
V_156:
F_92 ( V_141 ) ;
V_154:
F_24 ( V_152 ) ;
if ( F_99 ( V_71 ) )
goto V_27;
}
V_27:
return V_41 ;
}
