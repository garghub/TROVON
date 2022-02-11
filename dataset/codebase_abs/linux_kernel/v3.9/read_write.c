static inline int F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 & V_3 ;
}
static T_1 F_2 ( struct V_1 * V_1 , struct V_4 * V_4 ,
T_1 V_5 , T_1 V_6 )
{
if ( V_5 < 0 && ! F_1 ( V_1 ) )
return - V_7 ;
if ( V_5 > V_6 )
return - V_7 ;
if ( V_5 != V_1 -> V_8 ) {
V_1 -> V_8 = V_5 ;
V_1 -> V_9 = 0 ;
}
return V_5 ;
}
T_1
F_3 ( struct V_1 * V_1 , T_1 V_5 , int V_10 ,
T_1 V_6 , T_1 V_11 )
{
struct V_4 * V_4 = V_1 -> V_12 -> V_13 ;
switch ( V_10 ) {
case V_14 :
V_5 += V_11 ;
break;
case V_15 :
if ( V_5 == 0 )
return V_1 -> V_8 ;
F_4 ( & V_1 -> V_16 ) ;
V_5 = F_2 ( V_1 , V_4 , V_1 -> V_8 + V_5 ,
V_6 ) ;
F_5 ( & V_1 -> V_16 ) ;
return V_5 ;
case V_17 :
if ( V_5 >= V_11 )
return - V_18 ;
break;
case V_19 :
if ( V_5 >= V_11 )
return - V_18 ;
V_5 = V_11 ;
break;
}
return F_2 ( V_1 , V_4 , V_5 , V_6 ) ;
}
T_1 F_6 ( struct V_1 * V_1 , T_1 V_5 , int V_10 )
{
struct V_4 * V_4 = V_1 -> V_12 -> V_13 ;
return F_3 ( V_1 , V_5 , V_10 ,
V_4 -> V_20 -> V_21 ,
F_7 ( V_4 ) ) ;
}
T_1 F_8 ( struct V_1 * V_1 , T_1 V_5 , int V_10 )
{
return V_1 -> V_8 ;
}
T_1 F_9 ( struct V_1 * V_1 , T_1 V_5 , int V_10 )
{
return - V_22 ;
}
T_1 F_10 ( struct V_1 * V_1 , T_1 V_5 , int V_10 )
{
struct V_4 * V_4 = F_11 ( V_1 ) ;
T_1 V_23 ;
F_12 ( & V_4 -> V_24 ) ;
switch ( V_10 ) {
case V_14 :
V_5 += F_7 ( V_4 ) ;
break;
case V_15 :
if ( V_5 == 0 ) {
V_23 = V_1 -> V_8 ;
goto V_25;
}
V_5 += V_1 -> V_8 ;
break;
case V_17 :
if ( V_5 >= V_4 -> V_26 ) {
V_23 = - V_18 ;
goto V_25;
}
break;
case V_19 :
if ( V_5 >= V_4 -> V_26 ) {
V_23 = - V_18 ;
goto V_25;
}
V_5 = V_4 -> V_26 ;
break;
}
V_23 = - V_7 ;
if ( V_5 >= 0 || F_1 ( V_1 ) ) {
if ( V_5 != V_1 -> V_8 ) {
V_1 -> V_8 = V_5 ;
V_1 -> V_9 = 0 ;
}
V_23 = V_5 ;
}
V_25:
F_13 ( & V_4 -> V_24 ) ;
return V_23 ;
}
T_1 F_14 ( struct V_1 * V_1 , T_1 V_5 , int V_10 )
{
T_1 (* F_15)( struct V_1 * , T_1 , int );
F_15 = F_9 ;
if ( V_1 -> V_2 & V_27 ) {
if ( V_1 -> V_28 && V_1 -> V_28 -> V_29 )
F_15 = V_1 -> V_28 -> V_29 ;
}
return F_15 ( V_1 , V_5 , V_10 ) ;
}
int F_16 ( int V_30 , struct V_1 * V_1 , T_1 * V_31 , T_2 V_32 )
{
struct V_4 * V_4 ;
T_1 V_33 ;
int V_23 = - V_7 ;
V_4 = F_11 ( V_1 ) ;
if ( F_17 ( ( V_34 ) V_32 < 0 ) )
return V_23 ;
V_33 = * V_31 ;
if ( F_17 ( V_33 < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_23 ;
if ( V_32 >= - V_33 )
return - V_35 ;
} else if ( F_17 ( ( T_1 ) ( V_33 + V_32 ) < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_23 ;
}
if ( F_17 ( V_4 -> V_36 && F_18 ( V_4 ) ) ) {
V_23 = F_19 (
V_30 == V_37 ? V_38 : V_39 ,
V_4 , V_1 , V_33 , V_32 ) ;
if ( V_23 < 0 )
return V_23 ;
}
V_23 = F_20 ( V_1 ,
V_30 == V_37 ? V_40 : V_41 ) ;
if ( V_23 )
return V_23 ;
return V_32 > V_42 ? V_42 : V_32 ;
}
static void F_21 ( struct V_43 * V_44 )
{
F_22 ( V_45 ) ;
if ( ! F_23 ( V_44 ) )
F_24 () ;
else
F_25 ( V_44 ) ;
F_26 ( V_46 ) ;
}
V_34 F_27 ( struct V_1 * V_47 , char T_3 * V_48 , T_2 V_49 , T_1 * V_31 )
{
struct V_50 V_51 = { . V_52 = V_48 , . V_53 = V_49 } ;
struct V_43 V_43 ;
V_34 V_54 ;
F_28 ( & V_43 , V_47 ) ;
V_43 . V_55 = * V_31 ;
V_43 . V_56 = V_49 ;
V_43 . V_57 = V_49 ;
for (; ; ) {
V_54 = V_47 -> V_28 -> V_58 ( & V_43 , & V_51 , 1 , V_43 . V_55 ) ;
if ( V_54 != - V_59 )
break;
F_21 ( & V_43 ) ;
}
if ( - V_60 == V_54 )
V_54 = F_29 ( & V_43 ) ;
* V_31 = V_43 . V_55 ;
return V_54 ;
}
V_34 F_30 ( struct V_1 * V_1 , char T_3 * V_48 , T_2 V_32 , T_1 * V_33 )
{
V_34 V_54 ;
if ( ! ( V_1 -> V_2 & V_61 ) )
return - V_62 ;
if ( ! V_1 -> V_28 || ( ! V_1 -> V_28 -> V_63 && ! V_1 -> V_28 -> V_58 ) )
return - V_7 ;
if ( F_17 ( ! F_31 ( V_64 , V_48 , V_32 ) ) )
return - V_65 ;
V_54 = F_16 ( V_37 , V_1 , V_33 , V_32 ) ;
if ( V_54 >= 0 ) {
V_32 = V_54 ;
if ( V_1 -> V_28 -> V_63 )
V_54 = V_1 -> V_28 -> V_63 ( V_1 , V_48 , V_32 , V_33 ) ;
else
V_54 = F_27 ( V_1 , V_48 , V_32 , V_33 ) ;
if ( V_54 > 0 ) {
F_32 ( V_1 ) ;
F_33 ( V_66 , V_54 ) ;
}
F_34 ( V_66 ) ;
}
return V_54 ;
}
V_34 F_35 ( struct V_1 * V_47 , const char T_3 * V_48 , T_2 V_49 , T_1 * V_31 )
{
struct V_50 V_51 = { . V_52 = ( void T_3 * ) V_48 , . V_53 = V_49 } ;
struct V_43 V_43 ;
V_34 V_54 ;
F_28 ( & V_43 , V_47 ) ;
V_43 . V_55 = * V_31 ;
V_43 . V_56 = V_49 ;
V_43 . V_57 = V_49 ;
for (; ; ) {
V_54 = V_47 -> V_28 -> V_67 ( & V_43 , & V_51 , 1 , V_43 . V_55 ) ;
if ( V_54 != - V_59 )
break;
F_21 ( & V_43 ) ;
}
if ( - V_60 == V_54 )
V_54 = F_29 ( & V_43 ) ;
* V_31 = V_43 . V_55 ;
return V_54 ;
}
V_34 F_36 ( struct V_1 * V_1 , const char * V_48 , T_2 V_32 , T_1 * V_33 )
{
T_4 V_68 ;
const char T_3 * V_69 ;
V_34 V_54 ;
if ( ! V_1 -> V_28 || ( ! V_1 -> V_28 -> V_70 && ! V_1 -> V_28 -> V_67 ) )
return - V_7 ;
V_68 = F_37 () ;
F_38 ( F_39 () ) ;
V_69 = ( V_71 const char T_3 * ) V_48 ;
if ( V_32 > V_42 )
V_32 = V_42 ;
if ( V_1 -> V_28 -> V_70 )
V_54 = V_1 -> V_28 -> V_70 ( V_1 , V_69 , V_32 , V_33 ) ;
else
V_54 = F_35 ( V_1 , V_69 , V_32 , V_33 ) ;
F_38 ( V_68 ) ;
if ( V_54 > 0 ) {
F_40 ( V_1 ) ;
F_41 ( V_66 , V_54 ) ;
}
F_42 ( V_66 ) ;
return V_54 ;
}
V_34 F_43 ( struct V_1 * V_1 , const char T_3 * V_48 , T_2 V_32 , T_1 * V_33 )
{
V_34 V_54 ;
if ( ! ( V_1 -> V_2 & V_72 ) )
return - V_62 ;
if ( ! V_1 -> V_28 || ( ! V_1 -> V_28 -> V_70 && ! V_1 -> V_28 -> V_67 ) )
return - V_7 ;
if ( F_17 ( ! F_31 ( V_73 , V_48 , V_32 ) ) )
return - V_65 ;
V_54 = F_16 ( V_74 , V_1 , V_33 , V_32 ) ;
if ( V_54 >= 0 ) {
V_32 = V_54 ;
if ( V_1 -> V_28 -> V_70 )
V_54 = V_1 -> V_28 -> V_70 ( V_1 , V_48 , V_32 , V_33 ) ;
else
V_54 = F_35 ( V_1 , V_48 , V_32 , V_33 ) ;
if ( V_54 > 0 ) {
F_40 ( V_1 ) ;
F_41 ( V_66 , V_54 ) ;
}
F_42 ( V_66 ) ;
}
return V_54 ;
}
static inline T_1 F_44 ( struct V_1 * V_1 )
{
return V_1 -> V_8 ;
}
static inline void F_45 ( struct V_1 * V_1 , T_1 V_33 )
{
V_1 -> V_8 = V_33 ;
}
T_5 (F_46)( unsigned int V_75 , char T_3 * V_48 ,
T_2 V_32 , T_1 V_33 )
{
struct V_75 V_76 ;
V_34 V_54 = - V_62 ;
if ( V_33 < 0 )
return - V_7 ;
V_76 = F_47 ( V_75 ) ;
if ( V_76 . V_1 ) {
V_54 = - V_22 ;
if ( V_76 . V_1 -> V_2 & V_77 )
V_54 = F_30 ( V_76 . V_1 , V_48 , V_32 , & V_33 ) ;
F_48 ( V_76 ) ;
}
return V_54 ;
}
T_6 long F_49 ( long V_75 , long V_48 , long V_32 , T_1 V_33 )
{
return F_50 ( ( unsigned int ) V_75 , ( char T_3 * ) V_48 ,
( T_2 ) V_32 , V_33 ) ;
}
T_5 (F_51)( unsigned int V_75 , const char T_3 * V_48 ,
T_2 V_32 , T_1 V_33 )
{
struct V_75 V_76 ;
V_34 V_54 = - V_62 ;
if ( V_33 < 0 )
return - V_7 ;
V_76 = F_47 ( V_75 ) ;
if ( V_76 . V_1 ) {
V_54 = - V_22 ;
if ( V_76 . V_1 -> V_2 & V_78 )
V_54 = F_43 ( V_76 . V_1 , V_48 , V_32 , & V_33 ) ;
F_48 ( V_76 ) ;
}
return V_54 ;
}
T_6 long F_52 ( long V_75 , long V_48 , long V_32 , T_1 V_33 )
{
return F_53 ( ( unsigned int ) V_75 , ( const char T_3 * ) V_48 ,
( T_2 ) V_32 , V_33 ) ;
}
unsigned long F_54 ( struct V_50 * V_51 , unsigned long V_79 , T_2 V_80 )
{
unsigned long V_81 = 0 ;
T_2 V_49 = 0 ;
while ( V_81 < V_79 ) {
V_81 ++ ;
if ( V_49 + V_51 -> V_53 >= V_80 ) {
V_51 -> V_53 = V_80 - V_49 ;
break;
}
V_49 += V_51 -> V_53 ;
V_51 ++ ;
}
return V_81 ;
}
V_34 F_55 ( struct V_1 * V_47 , const struct V_50 * V_51 ,
unsigned long V_79 , T_2 V_49 , T_1 * V_31 , T_7 F_15 )
{
struct V_43 V_43 ;
V_34 V_54 ;
F_28 ( & V_43 , V_47 ) ;
V_43 . V_55 = * V_31 ;
V_43 . V_56 = V_49 ;
V_43 . V_57 = V_49 ;
for (; ; ) {
V_54 = F_15 ( & V_43 , V_51 , V_79 , V_43 . V_55 ) ;
if ( V_54 != - V_59 )
break;
F_21 ( & V_43 ) ;
}
if ( V_54 == - V_60 )
V_54 = F_29 ( & V_43 ) ;
* V_31 = V_43 . V_55 ;
return V_54 ;
}
V_34 F_56 ( struct V_1 * V_47 , struct V_50 * V_51 ,
unsigned long V_79 , T_1 * V_31 , T_8 F_15 )
{
struct V_50 * V_82 = V_51 ;
V_34 V_54 = 0 ;
while ( V_79 > 0 ) {
void T_3 * V_83 ;
T_2 V_49 ;
V_34 V_84 ;
V_83 = V_82 -> V_52 ;
V_49 = V_82 -> V_53 ;
V_82 ++ ;
V_79 -- ;
V_84 = F_15 ( V_47 , V_83 , V_49 , V_31 ) ;
if ( V_84 < 0 ) {
if ( ! V_54 )
V_54 = V_84 ;
break;
}
V_54 += V_84 ;
if ( V_84 != V_49 )
break;
}
return V_54 ;
}
V_34 F_57 ( int type , const struct V_50 T_3 * V_85 ,
unsigned long V_79 , unsigned long V_86 ,
struct V_50 * V_87 ,
struct V_50 * * V_88 )
{
unsigned long V_81 ;
V_34 V_54 ;
struct V_50 * V_51 = V_87 ;
if ( V_79 == 0 ) {
V_54 = 0 ;
goto V_25;
}
if ( V_79 > V_89 ) {
V_54 = - V_7 ;
goto V_25;
}
if ( V_79 > V_86 ) {
V_51 = F_58 ( V_79 * sizeof( struct V_50 ) , V_90 ) ;
if ( V_51 == NULL ) {
V_54 = - V_91 ;
goto V_25;
}
}
if ( F_59 ( V_51 , V_85 , V_79 * sizeof( * V_85 ) ) ) {
V_54 = - V_65 ;
goto V_25;
}
V_54 = 0 ;
for ( V_81 = 0 ; V_81 < V_79 ; V_81 ++ ) {
void T_3 * V_48 = V_51 [ V_81 ] . V_52 ;
V_34 V_49 = ( V_34 ) V_51 [ V_81 ] . V_53 ;
if ( V_49 < 0 ) {
V_54 = - V_7 ;
goto V_25;
}
if ( type >= 0
&& F_17 ( ! F_31 ( F_60 ( type ) , V_48 , V_49 ) ) ) {
V_54 = - V_65 ;
goto V_25;
}
if ( V_49 > V_42 - V_54 ) {
V_49 = V_42 - V_54 ;
V_51 [ V_81 ] . V_53 = V_49 ;
}
V_54 += V_49 ;
}
V_25:
* V_88 = V_51 ;
return V_54 ;
}
static V_34 F_61 ( int type , struct V_1 * V_1 ,
const struct V_50 T_3 * V_85 ,
unsigned long V_79 , T_1 * V_33 )
{
T_2 V_92 ;
struct V_50 V_93 [ V_94 ] ;
struct V_50 * V_51 = V_93 ;
V_34 V_54 ;
T_8 F_15 ;
T_7 V_95 ;
if ( ! V_1 -> V_28 ) {
V_54 = - V_7 ;
goto V_25;
}
V_54 = F_57 ( type , V_85 , V_79 ,
F_62 ( V_93 ) , V_93 , & V_51 ) ;
if ( V_54 <= 0 )
goto V_25;
V_92 = V_54 ;
V_54 = F_16 ( type , V_1 , V_33 , V_92 ) ;
if ( V_54 < 0 )
goto V_25;
V_95 = NULL ;
if ( type == V_37 ) {
F_15 = V_1 -> V_28 -> V_63 ;
V_95 = V_1 -> V_28 -> V_58 ;
} else {
F_15 = ( T_8 ) V_1 -> V_28 -> V_70 ;
V_95 = V_1 -> V_28 -> V_67 ;
}
if ( V_95 )
V_54 = F_55 ( V_1 , V_51 , V_79 , V_92 ,
V_33 , V_95 ) ;
else
V_54 = F_56 ( V_1 , V_51 , V_79 , V_33 , F_15 ) ;
V_25:
if ( V_51 != V_93 )
F_63 ( V_51 ) ;
if ( ( V_54 + ( type == V_37 ) ) > 0 ) {
if ( type == V_37 )
F_32 ( V_1 ) ;
else
F_40 ( V_1 ) ;
}
return V_54 ;
}
V_34 F_64 ( struct V_1 * V_1 , const struct V_50 T_3 * V_96 ,
unsigned long V_97 , T_1 * V_33 )
{
if ( ! ( V_1 -> V_2 & V_61 ) )
return - V_62 ;
if ( ! V_1 -> V_28 || ( ! V_1 -> V_28 -> V_58 && ! V_1 -> V_28 -> V_63 ) )
return - V_7 ;
return F_61 ( V_37 , V_1 , V_96 , V_97 , V_33 ) ;
}
V_34 F_65 ( struct V_1 * V_1 , const struct V_50 T_3 * V_96 ,
unsigned long V_97 , T_1 * V_33 )
{
if ( ! ( V_1 -> V_2 & V_72 ) )
return - V_62 ;
if ( ! V_1 -> V_28 || ( ! V_1 -> V_28 -> V_67 && ! V_1 -> V_28 -> V_70 ) )
return - V_7 ;
return F_61 ( V_74 , V_1 , V_96 , V_97 , V_33 ) ;
}
static inline T_1 F_66 ( unsigned long V_98 , unsigned long V_99 )
{
#define F_67 (BITS_PER_LONG / 2)
return ( ( ( T_1 ) V_98 << F_67 ) << F_67 ) | V_99 ;
}
V_34 F_68 ( int V_100 , int V_101 , T_1 * V_31 , T_2 V_32 ,
T_1 V_102 )
{
struct V_75 V_103 , V_25 ;
struct V_4 * V_104 , * V_105 ;
T_1 V_33 ;
V_34 V_23 ;
int V_106 ;
V_23 = - V_62 ;
V_103 = F_47 ( V_101 ) ;
if ( ! V_103 . V_1 )
goto V_25;
if ( ! ( V_103 . V_1 -> V_2 & V_61 ) )
goto V_107;
V_23 = - V_22 ;
if ( ! V_31 )
V_31 = & V_103 . V_1 -> V_8 ;
else
if ( ! ( V_103 . V_1 -> V_2 & V_77 ) )
goto V_107;
V_23 = F_16 ( V_37 , V_103 . V_1 , V_31 , V_32 ) ;
if ( V_23 < 0 )
goto V_107;
V_32 = V_23 ;
V_23 = - V_62 ;
V_25 = F_47 ( V_100 ) ;
if ( ! V_25 . V_1 )
goto V_107;
if ( ! ( V_25 . V_1 -> V_2 & V_72 ) )
goto V_108;
V_23 = - V_7 ;
V_104 = F_11 ( V_103 . V_1 ) ;
V_105 = F_11 ( V_25 . V_1 ) ;
V_23 = F_16 ( V_74 , V_25 . V_1 , & V_25 . V_1 -> V_8 , V_32 ) ;
if ( V_23 < 0 )
goto V_108;
V_32 = V_23 ;
if ( ! V_102 )
V_102 = F_69 ( V_104 -> V_20 -> V_21 , V_105 -> V_20 -> V_21 ) ;
V_33 = * V_31 ;
if ( F_17 ( V_33 + V_32 > V_102 ) ) {
V_23 = - V_35 ;
if ( V_33 >= V_102 )
goto V_108;
V_32 = V_102 - V_33 ;
}
V_106 = 0 ;
#if 0
if (in.file->f_flags & O_NONBLOCK)
fl = SPLICE_F_NONBLOCK;
#endif
V_23 = F_70 ( V_103 . V_1 , V_31 , V_25 . V_1 , V_32 , V_106 ) ;
if ( V_23 > 0 ) {
F_33 ( V_66 , V_23 ) ;
F_41 ( V_66 , V_23 ) ;
F_32 ( V_103 . V_1 ) ;
F_40 ( V_25 . V_1 ) ;
}
F_34 ( V_66 ) ;
F_42 ( V_66 ) ;
if ( * V_31 > V_102 )
V_23 = - V_35 ;
V_108:
F_48 ( V_25 ) ;
V_107:
F_48 ( V_103 ) ;
V_25:
return V_23 ;
}
