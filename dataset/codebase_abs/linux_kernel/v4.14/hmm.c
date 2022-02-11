static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 , struct V_6 * V_7 , bool V_8 )
{
T_1 V_9 = 0 ;
struct V_10 * V_11 ;
unsigned long V_12 ;
int V_13 ;
long V_14 [ V_15 ] = { 0 } ;
long V_16 [ V_15 ] = { 0 } ;
int V_17 = 0 ;
int V_18 = 0 ;
V_9 = F_2 ( V_5 , V_19 , L_1 ) ;
if ( V_9 <= 0 )
return 0 ;
V_17 += V_9 ;
F_3 ( & V_20 . V_21 , V_12 ) ;
F_4 (bo, bo_list, list) {
if ( ( V_8 && ( V_11 -> V_22 & V_23 ) ) ||
( ! V_8 && ! ( V_11 -> V_22 & V_23 ) ) ) {
V_9 = F_2 ( V_5 + V_17 , V_19 - V_17 ,
L_2 ,
V_24 [ V_11 -> type ] , V_11 -> V_25 ) ;
V_14 [ V_11 -> type ] += V_11 -> V_25 ;
V_16 [ V_11 -> type ] ++ ;
if ( V_9 > 0 )
V_17 += V_9 ;
}
}
F_5 ( & V_20 . V_21 , V_12 ) ;
for ( V_13 = 0 ; V_13 < V_15 ; V_13 ++ ) {
if ( V_16 [ V_13 ] ) {
V_9 = F_2 ( V_5 + V_17 + V_18 ,
V_19 - V_17 - V_18 ,
L_3 ,
V_16 [ V_13 ] , V_24 [ V_13 ] ,
V_14 [ V_13 ] * 4 ) ;
if ( V_9 > 0 )
V_18 += V_9 ;
}
}
return V_17 + V_18 + 1 ;
}
static T_1 F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
return F_1 ( V_2 , V_4 , V_5 , & V_20 . V_26 , true ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
return F_1 ( V_2 , V_4 , V_5 , & V_20 . V_26 , false ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
T_1 V_9 = 0 ;
struct V_27 * V_28 = V_29 . V_30 ;
unsigned long V_12 ;
if ( ! V_28 || ! V_28 -> V_31 )
return 0 ;
F_3 ( & V_28 -> V_21 , V_12 ) ;
V_9 = F_2 ( V_5 , V_19 , L_4 ,
V_28 -> V_32 , V_28 -> V_25 ) ;
F_5 ( & V_28 -> V_21 , V_12 ) ;
if ( V_9 > 0 )
V_9 ++ ;
return V_9 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
T_1 V_9 = 0 ;
struct V_33 * V_28 = V_34 . V_30 ;
unsigned long V_12 ;
if ( ! V_28 || ! V_28 -> V_31 )
return 0 ;
F_3 ( & V_28 -> V_21 , V_12 ) ;
V_9 = F_2 ( V_5 , V_19 , L_5 ,
V_28 -> V_25 , V_28 -> V_35 ) ;
F_5 ( & V_28 -> V_21 , V_12 ) ;
if ( V_9 > 0 )
V_9 ++ ;
return V_9 ;
}
int F_10 ( void )
{
int V_9 ;
V_9 = F_11 ( & V_20 , & V_36 ,
V_37 , V_38 ) ;
if ( V_9 )
F_12 ( V_39 , L_6 ) ;
V_40 = true ;
V_41 = F_13 ( 1 , V_42 , 0 , NULL , V_43 ) ;
if ( ! V_9 ) {
V_9 = F_14 ( & V_39 -> V_44 ,
V_45 ) ;
if ( V_9 )
F_12 ( V_39 ,
L_7 , V_46 ) ;
}
return V_9 ;
}
void F_15 ( void )
{
F_16 ( & V_39 -> V_44 , V_45 ) ;
F_17 ( V_41 ) ;
V_41 = 0 ;
F_18 ( & V_20 ) ;
V_40 = false ;
}
T_2 F_13 ( T_3 V_47 , enum V_48 type ,
int V_49 , void * V_50 , bool V_51 )
{
unsigned int V_25 ;
struct V_10 * V_11 ;
int V_9 ;
if ( ! V_40 )
F_10 () ;
V_25 = F_19 ( V_47 ) ;
V_11 = F_20 ( & V_20 , V_25 ) ;
if ( ! V_11 ) {
F_12 ( V_39 , L_8 ) ;
goto V_52;
}
V_9 = F_21 ( V_11 , type , V_49 , V_50 , V_51 ) ;
if ( V_9 ) {
F_12 ( V_39 , L_9 ) ;
goto V_53;
}
V_9 = F_22 ( V_11 ) ;
if ( V_9 ) {
F_12 ( V_39 , L_10 ) ;
goto V_54;
}
V_55 . V_56 += V_25 ;
return V_11 -> V_57 ;
V_54:
F_23 ( V_11 ) ;
V_53:
F_24 ( V_11 ) ;
V_52:
return 0 ;
}
void F_17 ( T_2 V_58 )
{
struct V_10 * V_11 ;
F_25 ( ! V_58 ) ;
V_11 = F_26 ( & V_20 , ( unsigned int ) V_58 ) ;
if ( ! V_11 ) {
F_12 ( V_39 ,
L_11 ,
( unsigned int ) V_58 ) ;
return;
}
V_55 . V_56 -= V_11 -> V_25 ;
F_27 ( V_11 ) ;
F_23 ( V_11 ) ;
F_24 ( V_11 ) ;
}
static inline int F_28 ( struct V_10 * V_11 , unsigned int V_59 )
{
if ( ! V_11 ) {
F_12 ( V_39 ,
L_12 ,
V_59 ) ;
return - V_60 ;
}
if ( ! F_29 ( V_11 ) ) {
F_12 ( V_39 ,
L_13 ) ;
return - V_60 ;
}
if ( ! F_30 ( V_11 ) ) {
F_12 ( V_39 ,
L_14 ) ;
return - V_60 ;
}
return 0 ;
}
static int F_31 ( T_2 V_58 , void * V_61 ,
unsigned int V_47 )
{
struct V_10 * V_11 ;
unsigned int V_62 , V_63 , V_64 ;
char * V_65 , * V_66 ;
int V_9 ;
V_11 = F_32 ( & V_20 , V_58 ) ;
V_9 = F_28 ( V_11 , V_58 ) ;
if ( V_9 )
return V_9 ;
V_66 = ( char * ) V_61 ;
while ( V_47 ) {
V_62 = ( V_58 - V_11 -> V_57 ) >> V_67 ;
V_63 = ( V_58 - V_11 -> V_57 ) - ( V_62 << V_67 ) ;
V_65 = ( char * ) F_33 ( V_11 -> V_68 [ V_62 ] . V_69 ) + V_63 ;
if ( ( V_47 + V_63 ) >= V_19 ) {
V_64 = V_19 - V_63 ;
V_47 -= V_64 ;
} else {
V_64 = V_47 ;
V_47 = 0 ;
}
V_58 += V_64 ;
if ( V_66 ) {
memcpy ( V_66 , V_65 , V_64 ) ;
V_66 += V_64 ;
}
F_34 ( V_65 , V_64 ) ;
F_35 ( V_11 -> V_68 [ V_62 ] . V_69 ) ;
}
return 0 ;
}
static int F_36 ( T_2 V_58 , void * V_61 , unsigned int V_47 )
{
struct V_10 * V_11 ;
int V_9 ;
V_11 = F_32 ( & V_20 , V_58 ) ;
V_9 = F_28 ( V_11 , V_58 ) ;
if ( V_9 )
return V_9 ;
if ( V_11 -> V_22 & V_70 || V_11 -> V_22 & V_71 ) {
void * V_65 = V_11 -> V_72 ;
V_65 += ( V_58 - V_11 -> V_57 ) ;
memcpy ( V_61 , V_65 , V_47 ) ;
if ( V_11 -> V_22 & V_71 )
F_34 ( V_65 , V_47 ) ;
} else {
void * V_73 ;
V_73 = F_37 ( V_11 , true ) ;
if ( ! V_73 )
return F_31 ( V_58 , V_61 , V_47 ) ;
else
V_73 = V_73 + ( V_58 - V_11 -> V_57 ) ;
memcpy ( V_61 , V_73 , V_47 ) ;
F_34 ( V_73 , V_47 ) ;
F_38 ( V_11 ) ;
}
return 0 ;
}
int F_39 ( T_2 V_58 , void * V_61 , unsigned int V_47 )
{
if ( ! V_61 ) {
F_12 ( V_39 ,
L_15 ) ;
return - V_60 ;
}
return F_36 ( V_58 , V_61 , V_47 ) ;
}
int F_40 ( T_2 V_58 , unsigned int V_47 )
{
return F_36 ( V_58 , NULL , V_47 ) ;
}
int F_41 ( T_2 V_58 , const void * V_61 , unsigned int V_47 )
{
struct V_10 * V_11 ;
unsigned int V_62 , V_63 , V_64 ;
char * V_65 , * V_66 ;
int V_9 ;
V_11 = F_32 ( & V_20 , V_58 ) ;
V_9 = F_28 ( V_11 , V_58 ) ;
if ( V_9 )
return V_9 ;
if ( V_11 -> V_22 & V_70 || V_11 -> V_22 & V_71 ) {
void * V_74 = V_11 -> V_72 ;
V_74 += ( V_58 - V_11 -> V_57 ) ;
memcpy ( V_74 , V_61 , V_47 ) ;
if ( V_11 -> V_22 & V_71 )
F_34 ( V_74 , V_47 ) ;
} else {
void * V_73 ;
V_73 = F_37 ( V_11 , true ) ;
if ( V_73 ) {
V_73 = V_73 + ( V_58 - V_11 -> V_57 ) ;
memcpy ( V_73 , V_61 , V_47 ) ;
F_34 ( V_73 , V_47 ) ;
F_38 ( V_11 ) ;
return 0 ;
}
}
V_65 = ( char * ) V_61 ;
while ( V_47 ) {
V_62 = ( V_58 - V_11 -> V_57 ) >> V_67 ;
V_63 = ( V_58 - V_11 -> V_57 ) - ( V_62 << V_67 ) ;
if ( F_42 () )
V_66 = ( char * ) F_43 ( V_11 -> V_68 [ V_62 ] . V_69 ) ;
else
V_66 = ( char * ) F_33 ( V_11 -> V_68 [ V_62 ] . V_69 ) ;
if ( ! V_66 ) {
F_12 ( V_39 ,
L_16 ,
V_62 ) ;
return - V_60 ;
}
V_66 += V_63 ;
if ( ( V_47 + V_63 ) >= V_19 ) {
V_64 = V_19 - V_63 ;
V_47 -= V_64 ;
} else {
V_64 = V_47 ;
V_47 = 0 ;
}
V_58 += V_64 ;
memcpy ( V_66 , V_65 , V_64 ) ;
V_65 += V_64 ;
F_34 ( V_66 , V_64 ) ;
if ( F_42 () )
F_44 ( V_66 - V_63 ) ;
else
F_35 ( V_11 -> V_68 [ V_62 ] . V_69 ) ;
}
return 0 ;
}
int F_45 ( T_2 V_58 , int V_75 , unsigned int V_47 )
{
struct V_10 * V_11 ;
unsigned int V_62 , V_63 , V_64 ;
char * V_66 ;
int V_9 ;
V_11 = F_32 ( & V_20 , V_58 ) ;
V_9 = F_28 ( V_11 , V_58 ) ;
if ( V_9 )
return V_9 ;
if ( V_11 -> V_22 & V_70 || V_11 -> V_22 & V_71 ) {
void * V_74 = V_11 -> V_72 ;
V_74 += ( V_58 - V_11 -> V_57 ) ;
memset ( V_74 , V_75 , V_47 ) ;
if ( V_11 -> V_22 & V_71 )
F_34 ( V_74 , V_47 ) ;
} else {
void * V_73 ;
V_73 = F_37 ( V_11 , true ) ;
if ( V_73 ) {
V_73 = V_73 + ( V_58 - V_11 -> V_57 ) ;
memset ( V_73 , V_75 , V_47 ) ;
F_34 ( V_73 , V_47 ) ;
F_38 ( V_11 ) ;
return 0 ;
}
}
while ( V_47 ) {
V_62 = ( V_58 - V_11 -> V_57 ) >> V_67 ;
V_63 = ( V_58 - V_11 -> V_57 ) - ( V_62 << V_67 ) ;
V_66 = ( char * ) F_33 ( V_11 -> V_68 [ V_62 ] . V_69 ) + V_63 ;
if ( ( V_47 + V_63 ) >= V_19 ) {
V_64 = V_19 - V_63 ;
V_47 -= V_64 ;
} else {
V_64 = V_47 ;
V_47 = 0 ;
}
V_58 += V_64 ;
memset ( V_66 , V_75 , V_64 ) ;
F_34 ( V_66 , V_64 ) ;
F_35 ( V_11 -> V_68 [ V_62 ] . V_69 ) ;
}
return 0 ;
}
T_4 F_46 ( T_2 V_58 )
{
unsigned int V_62 , V_63 ;
struct V_10 * V_11 ;
V_11 = F_32 ( & V_20 , V_58 ) ;
if ( ! V_11 ) {
F_12 ( V_39 ,
L_12 ,
V_58 ) ;
return - 1 ;
}
V_62 = ( V_58 - V_11 -> V_57 ) >> V_67 ;
V_63 = ( V_58 - V_11 -> V_57 ) - ( V_62 << V_67 ) ;
return F_47 ( V_11 -> V_68 [ V_62 ] . V_69 ) + V_63 ;
}
int F_48 ( struct V_76 * V_77 , T_2 V_58 )
{
struct V_10 * V_11 ;
V_11 = F_26 ( & V_20 , V_58 ) ;
if ( ! V_11 ) {
F_12 ( V_39 ,
L_11 ,
V_58 ) ;
return - V_60 ;
}
return F_49 ( V_77 , V_11 ) ;
}
void * F_50 ( T_2 V_58 , bool V_51 )
{
struct V_10 * V_11 ;
void * V_59 ;
V_11 = F_32 ( & V_20 , V_58 ) ;
if ( ! V_11 ) {
F_12 ( V_39 ,
L_12 ,
V_58 ) ;
return NULL ;
}
V_59 = F_37 ( V_11 , V_51 ) ;
if ( V_59 )
return V_59 + ( V_58 - V_11 -> V_57 ) ;
else
return NULL ;
}
void F_51 ( T_2 V_58 )
{
struct V_10 * V_11 ;
V_11 = F_32 ( & V_20 , V_58 ) ;
if ( ! V_11 ) {
F_52 ( V_39 ,
L_12 ,
V_58 ) ;
return;
}
F_53 ( V_11 ) ;
}
void F_54 ( T_2 V_58 )
{
struct V_10 * V_11 ;
V_11 = F_32 ( & V_20 , V_58 ) ;
if ( ! V_11 ) {
F_52 ( V_39 ,
L_12 ,
V_58 ) ;
return;
}
F_38 ( V_11 ) ;
}
int F_55 ( unsigned int V_35 , enum V_78 V_79 )
{
switch ( V_79 ) {
case V_80 :
V_29 . V_81 = & V_82 ;
return V_29 . V_81 -> V_83 ( & V_29 . V_30 ,
V_35 ) ;
case V_84 :
V_34 . V_81 = & V_85 ;
return V_34 . V_81 -> V_83 ( & V_34 . V_30 ,
V_35 ) ;
default:
F_12 ( V_39 , L_17 ) ;
return - V_60 ;
}
}
void F_56 ( enum V_78 V_79 )
{
switch ( V_79 ) {
case V_80 :
if ( V_29 . V_81 && V_29 . V_81 -> V_86 )
V_29 . V_81 -> V_86 ( & V_29 . V_30 ) ;
break;
case V_84 :
if ( V_34 . V_81 && V_34 . V_81 -> V_86 )
V_34 . V_81 -> V_86 ( & V_34 . V_30 ) ;
break;
default:
F_12 ( V_39 , L_17 ) ;
break;
}
return;
}
void * F_57 ( T_2 V_59 , bool V_51 )
{
return F_50 ( V_59 , V_51 ) ;
}
T_2 F_58 ( const void * V_59 )
{
struct V_10 * V_11 ;
V_11 = F_59 ( & V_20 , V_59 ) ;
if ( V_11 )
return V_11 -> V_57 ;
F_12 ( V_39 ,
L_18 ,
V_59 ) ;
return 0 ;
}
void F_60 ( const char * V_87 , const int line )
{
F_61 ( L_19 ,
V_55 . V_56 ,
V_55 . V_88 , V_55 . V_89 ,
V_55 . V_90 , V_55 . V_91 ,
V_55 . V_92 , V_55 . V_93 ) ;
}
void F_62 ( int V_94 , int V_95 , int V_96 )
{
V_55 . V_89 = V_94 ;
if ( 0 == V_55 . V_89 ) {
V_55 . V_89 = - 1 ;
V_55 . V_90 = - 1 ;
}
if ( ! V_95 ) {
V_55 . V_93 = - 1 ;
V_55 . V_92 = - 1 ;
} else {
V_55 . V_93 = 0 ;
V_55 . V_92 = V_96 ;
}
V_55 . V_88 = 0 ;
V_55 . V_91 = 0 ;
V_55 . V_56 = 0 ;
}
