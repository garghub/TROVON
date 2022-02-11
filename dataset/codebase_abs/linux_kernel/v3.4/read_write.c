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
T_1 V_6 )
{
struct V_4 * V_4 = V_1 -> V_11 -> V_12 ;
switch ( V_10 ) {
case V_13 :
V_5 += F_4 ( V_4 ) ;
break;
case V_14 :
if ( V_5 == 0 )
return V_1 -> V_8 ;
F_5 ( & V_1 -> V_15 ) ;
V_5 = F_2 ( V_1 , V_4 , V_1 -> V_8 + V_5 ,
V_6 ) ;
F_6 ( & V_1 -> V_15 ) ;
return V_5 ;
case V_16 :
if ( V_5 >= F_4 ( V_4 ) )
return - V_17 ;
break;
case V_18 :
if ( V_5 >= F_4 ( V_4 ) )
return - V_17 ;
V_5 = F_4 ( V_4 ) ;
break;
}
return F_2 ( V_1 , V_4 , V_5 , V_6 ) ;
}
T_1 F_7 ( struct V_1 * V_1 , T_1 V_5 , int V_10 )
{
struct V_4 * V_4 = V_1 -> V_11 -> V_12 ;
return F_3 ( V_1 , V_5 , V_10 ,
V_4 -> V_19 -> V_20 ) ;
}
T_1 F_8 ( struct V_1 * V_1 , T_1 V_5 , int V_10 )
{
return V_1 -> V_8 ;
}
T_1 F_9 ( struct V_1 * V_1 , T_1 V_5 , int V_10 )
{
return - V_21 ;
}
T_1 F_10 ( struct V_1 * V_1 , T_1 V_5 , int V_10 )
{
struct V_4 * V_4 = V_1 -> V_22 . V_23 -> V_24 ;
T_1 V_25 ;
F_11 ( & V_4 -> V_26 ) ;
switch ( V_10 ) {
case V_13 :
V_5 += F_4 ( V_4 ) ;
break;
case V_14 :
if ( V_5 == 0 ) {
V_25 = V_1 -> V_8 ;
goto V_27;
}
V_5 += V_1 -> V_8 ;
break;
case V_16 :
if ( V_5 >= V_4 -> V_28 ) {
V_25 = - V_17 ;
goto V_27;
}
break;
case V_18 :
if ( V_5 >= V_4 -> V_28 ) {
V_25 = - V_17 ;
goto V_27;
}
V_5 = V_4 -> V_28 ;
break;
}
V_25 = - V_7 ;
if ( V_5 >= 0 || F_1 ( V_1 ) ) {
if ( V_5 != V_1 -> V_8 ) {
V_1 -> V_8 = V_5 ;
V_1 -> V_9 = 0 ;
}
V_25 = V_5 ;
}
V_27:
F_12 ( & V_4 -> V_26 ) ;
return V_25 ;
}
T_1 F_13 ( struct V_1 * V_1 , T_1 V_5 , int V_10 )
{
T_1 (* F_14)( struct V_1 * , T_1 , int );
F_14 = F_9 ;
if ( V_1 -> V_2 & V_29 ) {
if ( V_1 -> V_30 && V_1 -> V_30 -> V_31 )
F_14 = V_1 -> V_30 -> V_31 ;
}
return F_14 ( V_1 , V_5 , V_10 ) ;
}
int F_15 ( int V_32 , struct V_1 * V_1 , T_1 * V_33 , T_2 V_34 )
{
struct V_4 * V_4 ;
T_1 V_35 ;
int V_25 = - V_7 ;
V_4 = V_1 -> V_22 . V_23 -> V_24 ;
if ( F_16 ( ( V_36 ) V_34 < 0 ) )
return V_25 ;
V_35 = * V_33 ;
if ( F_16 ( V_35 < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_25 ;
if ( V_34 >= - V_35 )
return - V_37 ;
} else if ( F_16 ( ( T_1 ) ( V_35 + V_34 ) < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_25 ;
}
if ( F_16 ( V_4 -> V_38 && F_17 ( V_4 ) ) ) {
V_25 = F_18 (
V_32 == V_39 ? V_40 : V_41 ,
V_4 , V_1 , V_35 , V_34 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_19 ( V_1 ,
V_32 == V_39 ? V_42 : V_43 ) ;
if ( V_25 )
return V_25 ;
return V_34 > V_44 ? V_44 : V_34 ;
}
static void F_20 ( struct V_45 * V_46 )
{
F_21 ( V_47 ) ;
if ( ! F_22 ( V_46 ) )
F_23 () ;
else
F_24 ( V_46 ) ;
F_25 ( V_48 ) ;
}
V_36 F_26 ( struct V_1 * V_49 , char T_3 * V_50 , T_2 V_51 , T_1 * V_33 )
{
struct V_52 V_53 = { . V_54 = V_50 , . V_55 = V_51 } ;
struct V_45 V_45 ;
V_36 V_56 ;
F_27 ( & V_45 , V_49 ) ;
V_45 . V_57 = * V_33 ;
V_45 . V_58 = V_51 ;
V_45 . V_59 = V_51 ;
for (; ; ) {
V_56 = V_49 -> V_30 -> V_60 ( & V_45 , & V_53 , 1 , V_45 . V_57 ) ;
if ( V_56 != - V_61 )
break;
F_20 ( & V_45 ) ;
}
if ( - V_62 == V_56 )
V_56 = F_28 ( & V_45 ) ;
* V_33 = V_45 . V_57 ;
return V_56 ;
}
V_36 F_29 ( struct V_1 * V_1 , char T_3 * V_50 , T_2 V_34 , T_1 * V_35 )
{
V_36 V_56 ;
if ( ! ( V_1 -> V_2 & V_63 ) )
return - V_64 ;
if ( ! V_1 -> V_30 || ( ! V_1 -> V_30 -> V_65 && ! V_1 -> V_30 -> V_60 ) )
return - V_7 ;
if ( F_16 ( ! F_30 ( V_66 , V_50 , V_34 ) ) )
return - V_67 ;
V_56 = F_15 ( V_39 , V_1 , V_35 , V_34 ) ;
if ( V_56 >= 0 ) {
V_34 = V_56 ;
if ( V_1 -> V_30 -> V_65 )
V_56 = V_1 -> V_30 -> V_65 ( V_1 , V_50 , V_34 , V_35 ) ;
else
V_56 = F_26 ( V_1 , V_50 , V_34 , V_35 ) ;
if ( V_56 > 0 ) {
F_31 ( V_1 ) ;
F_32 ( V_68 , V_56 ) ;
}
F_33 ( V_68 ) ;
}
return V_56 ;
}
V_36 F_34 ( struct V_1 * V_49 , const char T_3 * V_50 , T_2 V_51 , T_1 * V_33 )
{
struct V_52 V_53 = { . V_54 = ( void T_3 * ) V_50 , . V_55 = V_51 } ;
struct V_45 V_45 ;
V_36 V_56 ;
F_27 ( & V_45 , V_49 ) ;
V_45 . V_57 = * V_33 ;
V_45 . V_58 = V_51 ;
V_45 . V_59 = V_51 ;
for (; ; ) {
V_56 = V_49 -> V_30 -> V_69 ( & V_45 , & V_53 , 1 , V_45 . V_57 ) ;
if ( V_56 != - V_61 )
break;
F_20 ( & V_45 ) ;
}
if ( - V_62 == V_56 )
V_56 = F_28 ( & V_45 ) ;
* V_33 = V_45 . V_57 ;
return V_56 ;
}
V_36 F_35 ( struct V_1 * V_1 , const char T_3 * V_50 , T_2 V_34 , T_1 * V_35 )
{
V_36 V_56 ;
if ( ! ( V_1 -> V_2 & V_70 ) )
return - V_64 ;
if ( ! V_1 -> V_30 || ( ! V_1 -> V_30 -> V_71 && ! V_1 -> V_30 -> V_69 ) )
return - V_7 ;
if ( F_16 ( ! F_30 ( V_72 , V_50 , V_34 ) ) )
return - V_67 ;
V_56 = F_15 ( V_73 , V_1 , V_35 , V_34 ) ;
if ( V_56 >= 0 ) {
V_34 = V_56 ;
if ( V_1 -> V_30 -> V_71 )
V_56 = V_1 -> V_30 -> V_71 ( V_1 , V_50 , V_34 , V_35 ) ;
else
V_56 = F_34 ( V_1 , V_50 , V_34 , V_35 ) ;
if ( V_56 > 0 ) {
F_36 ( V_1 ) ;
F_37 ( V_68 , V_56 ) ;
}
F_38 ( V_68 ) ;
}
return V_56 ;
}
static inline T_1 F_39 ( struct V_1 * V_1 )
{
return V_1 -> V_8 ;
}
static inline void F_40 ( struct V_1 * V_1 , T_1 V_35 )
{
V_1 -> V_8 = V_35 ;
}
T_4 (F_41)( unsigned int V_74 , char T_3 * V_50 ,
T_2 V_34 , T_1 V_35 )
{
struct V_1 * V_1 ;
V_36 V_56 = - V_64 ;
int V_75 ;
if ( V_35 < 0 )
return - V_7 ;
V_1 = F_42 ( V_74 , & V_75 ) ;
if ( V_1 ) {
V_56 = - V_21 ;
if ( V_1 -> V_2 & V_76 )
V_56 = F_29 ( V_1 , V_50 , V_34 , & V_35 ) ;
F_43 ( V_1 , V_75 ) ;
}
return V_56 ;
}
T_5 long F_44 ( long V_74 , long V_50 , long V_34 , T_1 V_35 )
{
return F_45 ( ( unsigned int ) V_74 , ( char T_3 * ) V_50 ,
( T_2 ) V_34 , V_35 ) ;
}
T_4 (F_46)( unsigned int V_74 , const char T_3 * V_50 ,
T_2 V_34 , T_1 V_35 )
{
struct V_1 * V_1 ;
V_36 V_56 = - V_64 ;
int V_75 ;
if ( V_35 < 0 )
return - V_7 ;
V_1 = F_42 ( V_74 , & V_75 ) ;
if ( V_1 ) {
V_56 = - V_21 ;
if ( V_1 -> V_2 & V_77 )
V_56 = F_35 ( V_1 , V_50 , V_34 , & V_35 ) ;
F_43 ( V_1 , V_75 ) ;
}
return V_56 ;
}
T_5 long F_47 ( long V_74 , long V_50 , long V_34 , T_1 V_35 )
{
return F_48 ( ( unsigned int ) V_74 , ( const char T_3 * ) V_50 ,
( T_2 ) V_34 , V_35 ) ;
}
unsigned long F_49 ( struct V_52 * V_53 , unsigned long V_78 , T_2 V_79 )
{
unsigned long V_80 = 0 ;
T_2 V_51 = 0 ;
while ( V_80 < V_78 ) {
V_80 ++ ;
if ( V_51 + V_53 -> V_55 >= V_79 ) {
V_53 -> V_55 = V_79 - V_51 ;
break;
}
V_51 += V_53 -> V_55 ;
V_53 ++ ;
}
return V_80 ;
}
V_36 F_50 ( struct V_1 * V_49 , const struct V_52 * V_53 ,
unsigned long V_78 , T_2 V_51 , T_1 * V_33 , T_6 F_14 )
{
struct V_45 V_45 ;
V_36 V_56 ;
F_27 ( & V_45 , V_49 ) ;
V_45 . V_57 = * V_33 ;
V_45 . V_58 = V_51 ;
V_45 . V_59 = V_51 ;
for (; ; ) {
V_56 = F_14 ( & V_45 , V_53 , V_78 , V_45 . V_57 ) ;
if ( V_56 != - V_61 )
break;
F_20 ( & V_45 ) ;
}
if ( V_56 == - V_62 )
V_56 = F_28 ( & V_45 ) ;
* V_33 = V_45 . V_57 ;
return V_56 ;
}
V_36 F_51 ( struct V_1 * V_49 , struct V_52 * V_53 ,
unsigned long V_78 , T_1 * V_33 , T_7 F_14 )
{
struct V_52 * V_81 = V_53 ;
V_36 V_56 = 0 ;
while ( V_78 > 0 ) {
void T_3 * V_82 ;
T_2 V_51 ;
V_36 V_83 ;
V_82 = V_81 -> V_54 ;
V_51 = V_81 -> V_55 ;
V_81 ++ ;
V_78 -- ;
V_83 = F_14 ( V_49 , V_82 , V_51 , V_33 ) ;
if ( V_83 < 0 ) {
if ( ! V_56 )
V_56 = V_83 ;
break;
}
V_56 += V_83 ;
if ( V_83 != V_51 )
break;
}
return V_56 ;
}
V_36 F_52 ( int type , const struct V_52 T_3 * V_84 ,
unsigned long V_78 , unsigned long V_85 ,
struct V_52 * V_86 ,
struct V_52 * * V_87 ,
int V_88 )
{
unsigned long V_80 ;
V_36 V_56 ;
struct V_52 * V_53 = V_86 ;
if ( V_78 == 0 ) {
V_56 = 0 ;
goto V_27;
}
if ( V_78 > V_89 ) {
V_56 = - V_7 ;
goto V_27;
}
if ( V_78 > V_85 ) {
V_53 = F_53 ( V_78 * sizeof( struct V_52 ) , V_90 ) ;
if ( V_53 == NULL ) {
V_56 = - V_91 ;
goto V_27;
}
}
if ( F_54 ( V_53 , V_84 , V_78 * sizeof( * V_84 ) ) ) {
V_56 = - V_67 ;
goto V_27;
}
V_56 = 0 ;
for ( V_80 = 0 ; V_80 < V_78 ; V_80 ++ ) {
void T_3 * V_50 = V_53 [ V_80 ] . V_54 ;
V_36 V_51 = ( V_36 ) V_53 [ V_80 ] . V_55 ;
if ( V_51 < 0 ) {
V_56 = - V_7 ;
goto V_27;
}
if ( V_88
&& F_16 ( ! F_30 ( F_55 ( type ) , V_50 , V_51 ) ) ) {
V_56 = - V_67 ;
goto V_27;
}
if ( V_51 > V_44 - V_56 ) {
V_51 = V_44 - V_56 ;
V_53 [ V_80 ] . V_55 = V_51 ;
}
V_56 += V_51 ;
}
V_27:
* V_87 = V_53 ;
return V_56 ;
}
static V_36 F_56 ( int type , struct V_1 * V_1 ,
const struct V_52 T_3 * V_84 ,
unsigned long V_78 , T_1 * V_35 )
{
T_2 V_92 ;
struct V_52 V_93 [ V_94 ] ;
struct V_52 * V_53 = V_93 ;
V_36 V_56 ;
T_7 F_14 ;
T_6 V_95 ;
if ( ! V_1 -> V_30 ) {
V_56 = - V_7 ;
goto V_27;
}
V_56 = F_52 ( type , V_84 , V_78 ,
F_57 ( V_93 ) , V_93 , & V_53 , 1 ) ;
if ( V_56 <= 0 )
goto V_27;
V_92 = V_56 ;
V_56 = F_15 ( type , V_1 , V_35 , V_92 ) ;
if ( V_56 < 0 )
goto V_27;
V_95 = NULL ;
if ( type == V_39 ) {
F_14 = V_1 -> V_30 -> V_65 ;
V_95 = V_1 -> V_30 -> V_60 ;
} else {
F_14 = ( T_7 ) V_1 -> V_30 -> V_71 ;
V_95 = V_1 -> V_30 -> V_69 ;
}
if ( V_95 )
V_56 = F_50 ( V_1 , V_53 , V_78 , V_92 ,
V_35 , V_95 ) ;
else
V_56 = F_51 ( V_1 , V_53 , V_78 , V_35 , F_14 ) ;
V_27:
if ( V_53 != V_93 )
F_58 ( V_53 ) ;
if ( ( V_56 + ( type == V_39 ) ) > 0 ) {
if ( type == V_39 )
F_31 ( V_1 ) ;
else
F_36 ( V_1 ) ;
}
return V_56 ;
}
V_36 F_59 ( struct V_1 * V_1 , const struct V_52 T_3 * V_96 ,
unsigned long V_97 , T_1 * V_35 )
{
if ( ! ( V_1 -> V_2 & V_63 ) )
return - V_64 ;
if ( ! V_1 -> V_30 || ( ! V_1 -> V_30 -> V_60 && ! V_1 -> V_30 -> V_65 ) )
return - V_7 ;
return F_56 ( V_39 , V_1 , V_96 , V_97 , V_35 ) ;
}
V_36 F_60 ( struct V_1 * V_1 , const struct V_52 T_3 * V_96 ,
unsigned long V_97 , T_1 * V_35 )
{
if ( ! ( V_1 -> V_2 & V_70 ) )
return - V_64 ;
if ( ! V_1 -> V_30 || ( ! V_1 -> V_30 -> V_69 && ! V_1 -> V_30 -> V_71 ) )
return - V_7 ;
return F_56 ( V_73 , V_1 , V_96 , V_97 , V_35 ) ;
}
static inline T_1 F_61 ( unsigned long V_98 , unsigned long V_99 )
{
#define F_62 (BITS_PER_LONG / 2)
return ( ( ( T_1 ) V_98 << F_62 ) << F_62 ) | V_99 ;
}
static V_36 F_63 ( int V_100 , int V_101 , T_1 * V_33 ,
T_2 V_34 , T_1 V_102 )
{
struct V_1 * V_103 , * V_104 ;
struct V_4 * V_105 , * V_106 ;
T_1 V_35 ;
V_36 V_25 ;
int V_107 , V_108 , V_109 ;
V_25 = - V_64 ;
V_103 = F_42 ( V_101 , & V_107 ) ;
if ( ! V_103 )
goto V_27;
if ( ! ( V_103 -> V_2 & V_63 ) )
goto V_110;
V_25 = - V_21 ;
if ( ! V_33 )
V_33 = & V_103 -> V_8 ;
else
if ( ! ( V_103 -> V_2 & V_76 ) )
goto V_110;
V_25 = F_15 ( V_39 , V_103 , V_33 , V_34 ) ;
if ( V_25 < 0 )
goto V_110;
V_34 = V_25 ;
V_25 = - V_64 ;
V_104 = F_42 ( V_100 , & V_108 ) ;
if ( ! V_104 )
goto V_110;
if ( ! ( V_104 -> V_2 & V_70 ) )
goto V_111;
V_25 = - V_7 ;
V_105 = V_103 -> V_22 . V_23 -> V_24 ;
V_106 = V_104 -> V_22 . V_23 -> V_24 ;
V_25 = F_15 ( V_73 , V_104 , & V_104 -> V_8 , V_34 ) ;
if ( V_25 < 0 )
goto V_111;
V_34 = V_25 ;
if ( ! V_102 )
V_102 = F_64 ( V_105 -> V_19 -> V_20 , V_106 -> V_19 -> V_20 ) ;
V_35 = * V_33 ;
if ( F_16 ( V_35 + V_34 > V_102 ) ) {
V_25 = - V_37 ;
if ( V_35 >= V_102 )
goto V_111;
V_34 = V_102 - V_35 ;
}
V_109 = 0 ;
#if 0
if (in_file->f_flags & O_NONBLOCK)
fl = SPLICE_F_NONBLOCK;
#endif
V_25 = F_65 ( V_103 , V_33 , V_104 , V_34 , V_109 ) ;
if ( V_25 > 0 ) {
F_32 ( V_68 , V_25 ) ;
F_37 ( V_68 , V_25 ) ;
}
F_33 ( V_68 ) ;
F_38 ( V_68 ) ;
if ( * V_33 > V_102 )
V_25 = - V_37 ;
V_111:
F_43 ( V_104 , V_108 ) ;
V_110:
F_43 ( V_103 , V_107 ) ;
V_27:
return V_25 ;
}
