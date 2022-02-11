static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
V_2 -> V_4 = F_2 ( V_3 , V_5 ) ;
if ( V_2 -> V_4 == NULL )
return - V_6 ;
V_2 -> V_7 = V_3 ;
V_2 -> V_8 = V_2 -> V_4 ;
V_2 -> V_9 = V_2 -> V_4 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
static void F_5 ( struct V_1 * V_2 )
{
V_2 -> V_9 = V_2 -> V_8 ;
}
static unsigned F_6 ( struct V_1 * V_2 )
{
return ( V_2 -> V_7 + V_2 -> V_8 - V_2 -> V_9 ) % V_2 -> V_7 ;
}
static unsigned F_7 ( struct V_1 * V_2 )
{
return ( V_2 -> V_7 + V_2 -> V_9 - V_2 -> V_8 - 1 ) % V_2 -> V_7 ;
}
static unsigned
F_8 ( struct V_1 * V_2 , const char * V_10 , unsigned V_11 )
{
unsigned V_12 ;
V_12 = F_7 ( V_2 ) ;
if ( V_11 > V_12 )
V_11 = V_12 ;
if ( V_11 == 0 )
return 0 ;
V_12 = V_2 -> V_4 + V_2 -> V_7 - V_2 -> V_8 ;
if ( V_11 > V_12 ) {
memcpy ( V_2 -> V_8 , V_10 , V_12 ) ;
memcpy ( V_2 -> V_4 , V_10 + V_12 , V_11 - V_12 ) ;
V_2 -> V_8 = V_2 -> V_4 + V_11 - V_12 ;
} else {
memcpy ( V_2 -> V_8 , V_10 , V_11 ) ;
if ( V_11 < V_12 )
V_2 -> V_8 += V_11 ;
else
V_2 -> V_8 = V_2 -> V_4 ;
}
return V_11 ;
}
static unsigned
F_9 ( struct V_1 * V_2 , char * V_10 , unsigned V_11 )
{
unsigned V_12 ;
V_12 = F_6 ( V_2 ) ;
if ( V_11 > V_12 )
V_11 = V_12 ;
if ( V_11 == 0 )
return 0 ;
V_12 = V_2 -> V_4 + V_2 -> V_7 - V_2 -> V_9 ;
if ( V_11 > V_12 ) {
memcpy ( V_10 , V_2 -> V_9 , V_12 ) ;
memcpy ( V_10 + V_12 , V_2 -> V_4 , V_11 - V_12 ) ;
V_2 -> V_9 = V_2 -> V_4 + V_11 - V_12 ;
} else {
memcpy ( V_10 , V_2 -> V_9 , V_11 ) ;
if ( V_11 < V_12 )
V_2 -> V_9 += V_11 ;
else
V_2 -> V_9 = V_2 -> V_4 ;
}
return V_11 ;
}
struct V_13 *
F_10 ( struct V_14 * V_15 , unsigned V_12 , T_1 V_16 )
{
struct V_13 * V_17 ;
V_17 = F_11 ( V_15 , V_16 ) ;
if ( V_17 != NULL ) {
V_17 -> V_18 = V_12 ;
V_17 -> V_10 = F_2 ( V_12 , V_16 ) ;
if ( V_17 -> V_10 == NULL ) {
F_12 ( V_15 , V_17 ) ;
return NULL ;
}
}
return V_17 ;
}
void F_13 ( struct V_14 * V_15 , struct V_13 * V_17 )
{
F_4 ( V_17 -> V_10 ) ;
F_12 ( V_15 , V_17 ) ;
}
static unsigned
F_14 ( struct V_19 * V_20 , char * V_21 , unsigned V_3 )
{
unsigned V_12 ;
V_12 = F_6 ( & V_20 -> V_22 ) ;
if ( V_12 < V_3 )
V_3 = V_12 ;
if ( V_3 != 0 )
V_3 = F_9 ( & V_20 -> V_22 , V_21 , V_3 ) ;
return V_3 ;
}
static int F_15 ( struct V_19 * V_20 )
{
struct V_23 * V_24 = & V_20 -> V_25 ;
struct V_14 * V_26 = V_20 -> V_27 -> V_26 ;
int V_28 = 0 ;
bool V_29 = false ;
while ( ! V_20 -> V_30 && ! F_16 ( V_24 ) ) {
struct V_13 * V_17 ;
int V_12 ;
if ( V_20 -> V_31 >= V_32 )
break;
V_17 = F_17 ( V_24 -> V_33 , struct V_13 , V_34 ) ;
V_12 = F_14 ( V_20 , V_17 -> V_10 , V_26 -> V_35 ) ;
if ( V_12 == 0 ) {
F_18 ( & V_20 -> V_36 ) ;
break;
}
V_29 = true ;
V_17 -> V_18 = V_12 ;
F_19 ( & V_17 -> V_34 ) ;
V_17 -> V_37 = ( F_6 ( & V_20 -> V_22 ) == 0 ) ;
F_20 ( L_1 ,
V_20 -> V_38 , V_12 , * ( ( V_39 * ) V_17 -> V_10 ) ,
* ( ( V_39 * ) V_17 -> V_10 + 1 ) , * ( ( V_39 * ) V_17 -> V_10 + 2 ) ) ;
V_20 -> V_30 = true ;
F_21 ( & V_20 -> V_40 ) ;
V_28 = F_22 ( V_26 , V_17 , V_41 ) ;
F_23 ( & V_20 -> V_40 ) ;
V_20 -> V_30 = false ;
if ( V_28 ) {
F_24 ( L_2 ,
V_42 , L_3 , V_26 -> V_43 , V_28 ) ;
F_25 ( & V_17 -> V_34 , V_24 ) ;
break;
}
V_20 -> V_31 ++ ;
if ( ! V_20 -> V_27 )
break;
}
if ( V_29 && V_20 -> V_20 . V_44 )
F_26 ( V_20 -> V_20 . V_44 ) ;
return V_28 ;
}
static unsigned F_27 ( struct V_19 * V_20 )
{
struct V_23 * V_24 = & V_20 -> V_45 ;
struct V_14 * V_46 = V_20 -> V_27 -> V_46 ;
while ( ! F_16 ( V_24 ) ) {
struct V_13 * V_17 ;
int V_28 ;
struct V_47 * V_44 ;
V_44 = V_20 -> V_20 . V_44 ;
if ( ! V_44 )
break;
if ( V_20 -> V_48 >= V_32 )
break;
V_17 = F_17 ( V_24 -> V_33 , struct V_13 , V_34 ) ;
F_19 ( & V_17 -> V_34 ) ;
V_17 -> V_18 = V_46 -> V_35 ;
F_21 ( & V_20 -> V_40 ) ;
V_28 = F_22 ( V_46 , V_17 , V_41 ) ;
F_23 ( & V_20 -> V_40 ) ;
if ( V_28 ) {
F_24 ( L_2 ,
V_42 , L_3 , V_46 -> V_43 , V_28 ) ;
F_25 ( & V_17 -> V_34 , V_24 ) ;
break;
}
V_20 -> V_48 ++ ;
if ( ! V_20 -> V_27 )
break;
}
return V_20 -> V_48 ;
}
static void F_28 ( unsigned long V_49 )
{
struct V_19 * V_20 = ( void * ) V_49 ;
struct V_47 * V_44 ;
struct V_23 * V_50 = & V_20 -> V_51 ;
bool V_52 = false ;
bool V_53 = false ;
F_29 ( & V_20 -> V_40 ) ;
V_44 = V_20 -> V_20 . V_44 ;
while ( ! F_16 ( V_50 ) ) {
struct V_13 * V_17 ;
V_17 = F_30 ( V_50 , struct V_13 , V_34 ) ;
if ( V_44 && F_31 ( V_54 , & V_44 -> V_55 ) )
break;
switch ( V_17 -> V_28 ) {
case - V_56 :
V_52 = true ;
F_20 ( L_4 , V_20 -> V_38 ) ;
break;
default:
F_32 ( L_5 ,
V_20 -> V_38 , V_17 -> V_28 ) ;
case 0 :
break;
}
if ( V_17 -> V_57 ) {
char * V_21 = V_17 -> V_10 ;
unsigned V_3 = V_17 -> V_57 ;
unsigned V_58 ;
int V_11 ;
V_58 = V_20 -> V_59 ;
if ( V_58 ) {
V_21 += V_58 ;
V_3 -= V_58 ;
}
V_11 = F_33 ( & V_20 -> V_20 , V_21 ,
V_3 ) ;
if ( V_11 )
V_53 = true ;
if ( V_11 != V_3 ) {
V_20 -> V_59 += V_11 ;
F_20 ( L_6 ,
V_20 -> V_38 , V_11 , V_17 -> V_57 ) ;
break;
}
V_20 -> V_59 = 0 ;
}
F_34 ( & V_17 -> V_34 , & V_20 -> V_45 ) ;
V_20 -> V_48 -- ;
}
if ( V_53 )
F_35 ( & V_20 -> V_20 ) ;
if ( ! F_16 ( V_50 ) && V_44 ) {
if ( ! F_31 ( V_54 , & V_44 -> V_55 ) ) {
if ( V_53 )
F_36 ( & V_20 -> V_60 ) ;
else
F_32 ( L_7 ,
V_20 -> V_38 ) ;
}
}
if ( ! V_52 && V_20 -> V_27 )
F_27 ( V_20 ) ;
F_37 ( & V_20 -> V_40 ) ;
}
static void F_38 ( struct V_14 * V_15 , struct V_13 * V_17 )
{
struct V_19 * V_20 = V_15 -> V_61 ;
F_23 ( & V_20 -> V_40 ) ;
F_39 ( & V_17 -> V_34 , & V_20 -> V_51 ) ;
F_36 ( & V_20 -> V_60 ) ;
F_21 ( & V_20 -> V_40 ) ;
}
static void F_40 ( struct V_14 * V_15 , struct V_13 * V_17 )
{
struct V_19 * V_20 = V_15 -> V_61 ;
F_23 ( & V_20 -> V_40 ) ;
F_25 ( & V_17 -> V_34 , & V_20 -> V_25 ) ;
V_20 -> V_31 -- ;
switch ( V_17 -> V_28 ) {
default:
F_41 ( L_8 ,
V_42 , V_15 -> V_43 , V_17 -> V_28 ) ;
case 0 :
F_15 ( V_20 ) ;
break;
case - V_56 :
F_20 ( L_9 , V_42 , V_15 -> V_43 ) ;
break;
}
F_21 ( & V_20 -> V_40 ) ;
}
static void F_42 ( struct V_14 * V_15 , struct V_23 * V_62 ,
int * V_63 )
{
struct V_13 * V_17 ;
while ( ! F_16 ( V_62 ) ) {
V_17 = F_17 ( V_62 -> V_33 , struct V_13 , V_34 ) ;
F_19 ( & V_17 -> V_34 ) ;
F_13 ( V_15 , V_17 ) ;
if ( V_63 )
( * V_63 ) -- ;
}
}
static int F_43 ( struct V_14 * V_15 , struct V_23 * V_62 ,
void (* F_44)( struct V_14 * , struct V_13 * ) ,
int * V_63 )
{
int V_64 ;
struct V_13 * V_17 ;
int V_58 = V_63 ? V_32 - * V_63 : V_32 ;
for ( V_64 = 0 ; V_64 < V_58 ; V_64 ++ ) {
V_17 = F_10 ( V_15 , V_15 -> V_35 , V_41 ) ;
if ( ! V_17 )
return F_16 ( V_62 ) ? - V_6 : 0 ;
V_17 -> V_65 = F_44 ;
F_39 ( & V_17 -> V_34 , V_62 ) ;
if ( V_63 )
( * V_63 ) ++ ;
}
return 0 ;
}
static int F_45 ( struct V_19 * V_20 )
{
struct V_23 * V_62 = & V_20 -> V_45 ;
struct V_14 * V_15 = V_20 -> V_27 -> V_46 ;
int V_28 ;
unsigned V_66 ;
V_28 = F_43 ( V_15 , V_62 , F_38 ,
& V_20 -> V_67 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_43 ( V_20 -> V_27 -> V_26 , & V_20 -> V_25 ,
F_40 , & V_20 -> V_68 ) ;
if ( V_28 ) {
F_42 ( V_15 , V_62 , & V_20 -> V_67 ) ;
return V_28 ;
}
V_20 -> V_59 = 0 ;
V_66 = F_27 ( V_20 ) ;
if ( V_66 ) {
F_26 ( V_20 -> V_20 . V_44 ) ;
} else {
F_42 ( V_15 , V_62 , & V_20 -> V_67 ) ;
F_42 ( V_20 -> V_27 -> V_26 , & V_20 -> V_25 ,
& V_20 -> V_68 ) ;
V_28 = - V_69 ;
}
return V_28 ;
}
static int F_46 ( struct V_47 * V_44 , struct V_70 * V_70 )
{
int V_38 = V_44 -> V_71 ;
struct V_19 * V_20 ;
int V_28 ;
do {
F_47 ( & V_72 [ V_38 ] . V_73 ) ;
V_20 = V_72 [ V_38 ] . V_20 ;
if ( ! V_20 )
V_28 = - V_74 ;
else {
F_29 ( & V_20 -> V_40 ) ;
if ( V_20 -> V_20 . V_11 ) {
V_28 = 0 ;
V_20 -> V_20 . V_11 ++ ;
} else if ( V_20 -> V_75 ) {
V_28 = - V_76 ;
} else {
V_28 = - V_77 ;
V_20 -> V_75 = true ;
}
F_37 ( & V_20 -> V_40 ) ;
}
F_48 ( & V_72 [ V_38 ] . V_73 ) ;
switch ( V_28 ) {
default:
return V_28 ;
case - V_77 :
break;
case - V_76 :
F_49 ( 1 ) ;
break;
}
} while ( V_28 != - V_77 );
F_29 ( & V_20 -> V_40 ) ;
if ( V_20 -> V_22 . V_4 == NULL ) {
F_37 ( & V_20 -> V_40 ) ;
V_28 = F_1 ( & V_20 -> V_22 , V_78 ) ;
F_29 ( & V_20 -> V_40 ) ;
if ( V_28 ) {
F_24 ( L_10 ,
V_20 -> V_38 , V_44 , V_70 ) ;
V_20 -> V_75 = false ;
goto V_79;
}
}
V_44 -> V_61 = V_20 ;
V_20 -> V_20 . V_44 = V_44 ;
V_20 -> V_20 . V_11 = 1 ;
V_20 -> V_75 = false ;
if ( V_20 -> V_27 ) {
struct V_80 * V_81 = V_20 -> V_27 ;
F_24 ( L_11 , V_20 -> V_38 ) ;
F_45 ( V_20 ) ;
if ( V_81 -> V_82 )
V_81 -> V_82 ( V_81 ) ;
}
F_24 ( L_12 , V_20 -> V_38 , V_44 , V_70 ) ;
V_28 = 0 ;
V_79:
F_37 ( & V_20 -> V_40 ) ;
return V_28 ;
}
static int F_50 ( struct V_19 * V_83 )
{
int V_84 ;
F_29 ( & V_83 -> V_40 ) ;
V_84 = ( V_83 -> V_27 == NULL ) || ! F_6 ( & V_83 -> V_22 ) ;
F_37 ( & V_83 -> V_40 ) ;
return V_84 ;
}
static void F_51 ( struct V_47 * V_44 , struct V_70 * V_70 )
{
struct V_19 * V_20 = V_44 -> V_61 ;
struct V_80 * V_81 ;
F_29 ( & V_20 -> V_40 ) ;
if ( V_20 -> V_20 . V_11 != 1 ) {
if ( V_20 -> V_20 . V_11 == 0 )
F_52 ( 1 ) ;
else
-- V_20 -> V_20 . V_11 ;
goto exit;
}
F_24 ( L_13 , V_20 -> V_38 , V_44 , V_70 ) ;
V_20 -> V_75 = true ;
V_20 -> V_20 . V_11 = 0 ;
V_81 = V_20 -> V_27 ;
if ( V_81 && V_81 -> V_52 )
V_81 -> V_52 ( V_81 ) ;
if ( F_6 ( & V_20 -> V_22 ) > 0 && V_81 ) {
F_37 ( & V_20 -> V_40 ) ;
F_53 ( V_20 -> V_36 ,
F_50 ( V_20 ) ,
V_85 * V_86 ) ;
F_29 ( & V_20 -> V_40 ) ;
V_81 = V_20 -> V_27 ;
}
if ( V_81 == NULL )
F_3 ( & V_20 -> V_22 ) ;
else
F_5 ( & V_20 -> V_22 ) ;
V_20 -> V_20 . V_44 = NULL ;
V_20 -> V_75 = false ;
F_24 ( L_14 ,
V_20 -> V_38 , V_44 , V_70 ) ;
F_54 ( & V_20 -> V_87 ) ;
exit:
F_37 ( & V_20 -> V_40 ) ;
}
static int F_55 ( struct V_47 * V_44 , const unsigned char * V_10 , int V_11 )
{
struct V_19 * V_20 = V_44 -> V_61 ;
unsigned long V_55 ;
int V_28 ;
F_20 ( L_15 ,
V_20 -> V_38 , V_44 , V_11 ) ;
F_56 ( & V_20 -> V_40 , V_55 ) ;
if ( V_11 )
V_11 = F_8 ( & V_20 -> V_22 , V_10 , V_11 ) ;
if ( V_20 -> V_27 )
V_28 = F_15 ( V_20 ) ;
F_57 ( & V_20 -> V_40 , V_55 ) ;
return V_11 ;
}
static int F_58 ( struct V_47 * V_44 , unsigned char V_88 )
{
struct V_19 * V_20 = V_44 -> V_61 ;
unsigned long V_55 ;
int V_28 ;
F_20 ( L_16 ,
V_20 -> V_38 , V_44 , V_88 , F_59 ( 0 ) ) ;
F_56 ( & V_20 -> V_40 , V_55 ) ;
V_28 = F_8 ( & V_20 -> V_22 , & V_88 , 1 ) ;
F_57 ( & V_20 -> V_40 , V_55 ) ;
return V_28 ;
}
static void F_60 ( struct V_47 * V_44 )
{
struct V_19 * V_20 = V_44 -> V_61 ;
unsigned long V_55 ;
F_20 ( L_17 , V_20 -> V_38 , V_44 ) ;
F_56 ( & V_20 -> V_40 , V_55 ) ;
if ( V_20 -> V_27 )
F_15 ( V_20 ) ;
F_57 ( & V_20 -> V_40 , V_55 ) ;
}
static int F_61 ( struct V_47 * V_44 )
{
struct V_19 * V_20 = V_44 -> V_61 ;
unsigned long V_55 ;
int V_89 = 0 ;
F_56 ( & V_20 -> V_40 , V_55 ) ;
if ( V_20 -> V_27 )
V_89 = F_7 ( & V_20 -> V_22 ) ;
F_57 ( & V_20 -> V_40 , V_55 ) ;
F_20 ( L_18 ,
V_20 -> V_38 , V_44 , V_89 ) ;
return V_89 ;
}
static int F_62 ( struct V_47 * V_44 )
{
struct V_19 * V_20 = V_44 -> V_61 ;
unsigned long V_55 ;
int V_90 = 0 ;
F_56 ( & V_20 -> V_40 , V_55 ) ;
V_90 = F_6 ( & V_20 -> V_22 ) ;
F_57 ( & V_20 -> V_40 , V_55 ) ;
F_20 ( L_19 ,
V_20 -> V_38 , V_44 , V_90 ) ;
return V_90 ;
}
static void F_63 ( struct V_47 * V_44 )
{
struct V_19 * V_20 = V_44 -> V_61 ;
unsigned long V_55 ;
F_56 ( & V_20 -> V_40 , V_55 ) ;
if ( V_20 -> V_27 ) {
F_36 ( & V_20 -> V_60 ) ;
F_20 ( L_20 , V_20 -> V_38 ) ;
}
F_57 ( & V_20 -> V_40 , V_55 ) ;
}
static int F_64 ( struct V_47 * V_44 , int V_91 )
{
struct V_19 * V_20 = V_44 -> V_61 ;
int V_28 = 0 ;
struct V_80 * V_81 ;
F_20 ( L_21 ,
V_20 -> V_38 , V_91 ) ;
F_29 ( & V_20 -> V_40 ) ;
V_81 = V_20 -> V_27 ;
if ( V_81 && V_81 -> V_92 )
V_28 = V_81 -> V_92 ( V_81 , V_91 ) ;
F_37 ( & V_20 -> V_40 ) ;
return V_28 ;
}
static int
F_65 ( unsigned V_38 , struct V_93 * V_94 )
{
struct V_19 * V_20 ;
int V_95 = 0 ;
F_47 ( & V_72 [ V_38 ] . V_73 ) ;
if ( V_72 [ V_38 ] . V_20 ) {
V_95 = - V_76 ;
goto V_46;
}
V_20 = F_66 ( sizeof( struct V_19 ) , V_5 ) ;
if ( V_20 == NULL ) {
V_95 = - V_6 ;
goto V_46;
}
F_67 ( & V_20 -> V_20 ) ;
F_68 ( & V_20 -> V_40 ) ;
F_69 ( & V_20 -> V_36 ) ;
F_69 ( & V_20 -> V_87 ) ;
F_70 ( & V_20 -> V_60 , F_28 , ( unsigned long ) V_20 ) ;
F_71 ( & V_20 -> V_45 ) ;
F_71 ( & V_20 -> V_51 ) ;
F_71 ( & V_20 -> V_25 ) ;
V_20 -> V_38 = V_38 ;
V_20 -> V_96 = * V_94 ;
V_72 [ V_38 ] . V_20 = V_20 ;
V_46:
F_48 ( & V_72 [ V_38 ] . V_73 ) ;
return V_95 ;
}
static int F_72 ( struct V_19 * V_20 )
{
int V_84 ;
F_29 ( & V_20 -> V_40 ) ;
V_84 = ( V_20 -> V_20 . V_11 == 0 ) && ! V_20 -> V_75 ;
F_37 ( & V_20 -> V_40 ) ;
return V_84 ;
}
static void F_73 ( struct V_19 * V_20 )
{
F_74 ( & V_20 -> V_60 ) ;
F_75 ( V_20 -> V_87 , F_72 ( V_20 ) ) ;
F_52 ( V_20 -> V_27 != NULL ) ;
F_76 ( & V_20 -> V_20 ) ;
F_4 ( V_20 ) ;
}
void F_77 ( unsigned char V_38 )
{
struct V_19 * V_20 ;
F_47 ( & V_72 [ V_38 ] . V_73 ) ;
if ( F_52 ( ! V_72 [ V_38 ] . V_20 ) ) {
F_48 ( & V_72 [ V_38 ] . V_73 ) ;
return;
}
V_20 = V_72 [ V_38 ] . V_20 ;
V_72 [ V_38 ] . V_20 = NULL ;
F_48 ( & V_72 [ V_38 ] . V_73 ) ;
F_73 ( V_20 ) ;
F_78 ( V_97 , V_38 ) ;
}
int F_79 ( unsigned char * V_98 )
{
struct V_93 V_94 ;
struct V_99 * V_100 ;
int V_95 ;
int V_38 ;
V_94 . V_101 = F_80 ( 9600 ) ;
V_94 . V_102 = 8 ;
V_94 . V_103 = V_104 ;
V_94 . V_105 = V_106 ;
for ( V_38 = 0 ; V_38 < V_107 ; V_38 ++ ) {
V_95 = F_65 ( V_38 , & V_94 ) ;
if ( V_95 == - V_76 )
continue;
if ( V_95 )
return V_95 ;
break;
}
if ( V_95 )
return V_95 ;
V_100 = F_81 ( & V_72 [ V_38 ] . V_20 -> V_20 ,
V_97 , V_38 , NULL ) ;
if ( F_82 ( V_100 ) ) {
struct V_19 * V_20 ;
F_83 ( L_22 ,
V_42 , V_38 , F_84 ( V_100 ) ) ;
V_95 = F_84 ( V_100 ) ;
V_20 = V_72 [ V_38 ] . V_20 ;
V_72 [ V_38 ] . V_20 = NULL ;
F_73 ( V_20 ) ;
goto V_108;
}
* V_98 = V_38 ;
V_108:
return V_95 ;
}
int F_85 ( struct V_80 * V_81 , V_39 V_38 )
{
struct V_19 * V_20 ;
unsigned long V_55 ;
int V_28 ;
if ( V_38 >= V_107 )
return - V_109 ;
V_20 = V_72 [ V_38 ] . V_20 ;
if ( ! V_20 ) {
F_83 ( L_23 , V_38 ) ;
return - V_110 ;
}
if ( V_20 -> V_27 ) {
F_83 ( L_24 , V_38 ) ;
return - V_76 ;
}
V_28 = F_86 ( V_81 -> V_26 ) ;
if ( V_28 < 0 )
return V_28 ;
V_81 -> V_26 -> V_61 = V_20 ;
V_28 = F_86 ( V_81 -> V_46 ) ;
if ( V_28 < 0 )
goto V_111;
V_81 -> V_46 -> V_61 = V_20 ;
F_56 ( & V_20 -> V_40 , V_55 ) ;
V_81 -> V_112 = V_20 ;
V_20 -> V_27 = V_81 ;
V_81 -> V_96 = V_20 -> V_96 ;
if ( V_20 -> V_20 . V_11 ) {
F_24 ( L_25 , V_20 -> V_38 ) ;
F_45 ( V_20 ) ;
if ( V_81 -> V_82 )
V_81 -> V_82 ( V_81 ) ;
} else {
if ( V_81 -> V_52 )
V_81 -> V_52 ( V_81 ) ;
}
F_57 ( & V_20 -> V_40 , V_55 ) ;
return V_28 ;
V_111:
F_87 ( V_81 -> V_26 ) ;
return V_28 ;
}
void F_88 ( struct V_80 * V_81 )
{
struct V_19 * V_20 = V_81 -> V_112 ;
unsigned long V_55 ;
if ( ! V_20 )
return;
F_56 ( & V_20 -> V_40 , V_55 ) ;
V_20 -> V_96 = V_81 -> V_96 ;
V_20 -> V_27 = NULL ;
V_81 -> V_112 = NULL ;
if ( V_20 -> V_20 . V_11 > 0 || V_20 -> V_75 ) {
F_18 ( & V_20 -> V_36 ) ;
if ( V_20 -> V_20 . V_44 )
F_89 ( V_20 -> V_20 . V_44 ) ;
}
F_57 ( & V_20 -> V_40 , V_55 ) ;
F_87 ( V_81 -> V_46 ) ;
F_87 ( V_81 -> V_26 ) ;
F_56 ( & V_20 -> V_40 , V_55 ) ;
if ( V_20 -> V_20 . V_11 == 0 && ! V_20 -> V_75 )
F_3 ( & V_20 -> V_22 ) ;
F_42 ( V_81 -> V_46 , & V_20 -> V_45 , NULL ) ;
F_42 ( V_81 -> V_46 , & V_20 -> V_51 , NULL ) ;
F_42 ( V_81 -> V_26 , & V_20 -> V_25 , NULL ) ;
V_20 -> V_67 = V_20 -> V_48 =
V_20 -> V_68 = V_20 -> V_31 = 0 ;
F_57 ( & V_20 -> V_40 , V_55 ) ;
}
static int F_90 ( void )
{
unsigned V_64 ;
int V_28 ;
V_97 = F_91 ( V_107 ) ;
if ( ! V_97 )
return - V_6 ;
V_97 -> V_113 = L_26 ;
V_97 -> V_43 = L_27 ;
V_97 -> type = V_114 ;
V_97 -> V_115 = V_116 ;
V_97 -> V_55 = V_117 | V_118 ;
V_97 -> V_119 = V_120 ;
V_97 -> V_119 . V_121 =
V_122 | V_123 | V_124 | V_125 | V_126 ;
V_97 -> V_119 . V_127 = 9600 ;
V_97 -> V_119 . V_128 = 9600 ;
F_92 ( V_97 , & V_129 ) ;
for ( V_64 = 0 ; V_64 < V_107 ; V_64 ++ )
F_93 ( & V_72 [ V_64 ] . V_73 ) ;
V_28 = F_94 ( V_97 ) ;
if ( V_28 ) {
F_83 ( L_28 ,
V_42 , V_28 ) ;
goto V_130;
}
F_24 ( L_29 , V_42 ,
V_107 ,
( V_107 == 1 ) ? L_30 : L_31 ) ;
return V_28 ;
V_130:
F_95 ( V_97 ) ;
V_97 = NULL ;
return V_28 ;
}
static void F_96 ( void )
{
F_97 ( V_97 ) ;
F_95 ( V_97 ) ;
V_97 = NULL ;
}
