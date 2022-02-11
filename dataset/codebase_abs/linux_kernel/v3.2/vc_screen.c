static int
F_1 ( struct V_1 * V_2 , unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = V_4 ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 =
F_2 ( V_2 , struct V_9 , V_11 ) ;
int V_12 = V_10 -> V_13 ;
if ( V_3 != V_14 )
return V_15 ;
if ( V_12 == 0 )
V_12 = V_16 ;
else
V_12 -- ;
if ( V_12 != V_8 -> V_17 )
return V_15 ;
V_10 -> V_18 = false ;
F_3 ( & V_10 -> V_19 ) ;
F_4 ( & V_10 -> V_20 , V_21 , V_22 ) ;
return V_23 ;
}
static void
F_5 ( struct V_9 * V_10 )
{
F_6 ( & V_10 -> V_11 ) ;
F_7 ( V_10 ) ;
}
static struct V_9 *
F_8 ( struct V_24 * V_24 )
{
struct V_9 * V_10 = V_24 -> V_25 ;
if ( V_10 )
return V_10 ;
V_10 = F_9 ( sizeof( * V_10 ) , V_26 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_13 = F_10 ( V_24 -> V_27 . V_28 -> V_29 ) & 127 ;
F_11 ( & V_10 -> V_19 ) ;
V_10 -> V_11 . V_30 = F_1 ;
if ( F_12 ( & V_10 -> V_11 ) != 0 ) {
F_7 ( V_10 ) ;
return NULL ;
}
F_13 ( & V_24 -> V_31 ) ;
if ( ! V_24 -> V_25 ) {
V_24 -> V_25 = V_10 ;
} else {
F_5 ( V_10 ) ;
V_10 = V_24 -> V_25 ;
}
F_14 ( & V_24 -> V_31 ) ;
return V_10 ;
}
static struct V_7 *
F_15 ( struct V_32 * V_32 , int * V_33 )
{
unsigned int V_12 = F_10 ( V_32 ) & 127 ;
F_16 () ;
if ( V_12 == 0 ) {
V_12 = V_16 ;
if ( V_33 )
* V_33 = 1 ;
} else {
V_12 -- ;
if ( V_33 )
* V_33 = 0 ;
}
return V_34 [ V_12 ] . V_35 ;
}
static int
F_17 ( struct V_32 * V_32 )
{
int V_36 ;
int V_37 = F_10 ( V_32 ) ;
struct V_7 * V_8 ;
F_16 () ;
V_8 = F_15 ( V_32 , NULL ) ;
if ( ! V_8 )
return - V_38 ;
V_36 = V_8 -> V_39 * V_8 -> V_40 ;
if ( V_37 & 128 )
V_36 = 2 * V_36 + V_41 ;
return V_36 ;
}
static T_1 F_18 ( struct V_24 * V_24 , T_1 V_42 , int V_43 )
{
int V_36 ;
F_19 () ;
V_36 = F_17 ( V_24 -> V_27 . V_28 -> V_29 ) ;
F_20 () ;
if ( V_36 < 0 )
return V_36 ;
switch ( V_43 ) {
default:
return - V_44 ;
case 2 :
V_42 += V_36 ;
break;
case 1 :
V_42 += V_24 -> V_45 ;
case 0 :
break;
}
if ( V_42 < 0 || V_42 > V_36 ) {
return - V_44 ;
}
V_24 -> V_45 = V_42 ;
return V_24 -> V_45 ;
}
static T_2
F_21 ( struct V_24 * V_24 , char T_3 * V_46 , T_4 V_47 , T_1 * V_48 )
{
struct V_32 * V_32 = V_24 -> V_27 . V_28 -> V_29 ;
unsigned int V_12 = F_10 ( V_32 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
long V_49 ;
long V_50 , V_51 ;
int V_52 , V_53 , V_33 ;
unsigned short * V_54 = NULL ;
T_2 V_55 ;
char * V_56 ;
V_56 = ( char * ) F_22 ( V_26 ) ;
if ( ! V_56 )
return - V_57 ;
V_49 = * V_48 ;
F_19 () ;
V_50 = ( V_12 & 128 ) ;
V_55 = - V_38 ;
V_8 = F_15 ( V_32 , & V_33 ) ;
if ( ! V_8 )
goto V_58;
V_55 = - V_44 ;
if ( V_49 < 0 )
goto V_58;
V_10 = V_24 -> V_25 ;
if ( V_47 && V_10 )
V_10 -> V_18 = true ;
V_51 = 0 ;
V_55 = 0 ;
while ( V_47 ) {
char * V_59 , * V_60 ;
long V_61 , V_36 ;
T_2 V_62 ;
long V_63 = V_49 ;
V_36 = F_17 ( V_32 ) ;
if ( V_36 < 0 ) {
if ( V_51 )
break;
V_55 = V_36 ;
goto V_58;
}
if ( V_49 >= V_36 )
break;
if ( V_47 > V_36 - V_49 )
V_47 = V_36 - V_49 ;
V_61 = V_47 ;
if ( V_61 > V_64 )
V_61 = V_64 ;
V_60 = V_59 = V_56 ;
V_62 = V_61 ;
V_53 = V_8 -> V_40 ;
if ( ! V_50 ) {
V_54 = F_23 ( V_8 , V_63 , V_33 ) ;
V_52 = V_63 % V_53 ;
V_63 += V_53 - V_52 ;
while ( V_61 -- > 0 ) {
* V_59 ++ = ( F_24 ( V_8 , V_54 ++ ) & 0xff ) ;
if ( ++ V_52 == V_53 ) {
V_54 = F_23 ( V_8 , V_63 , V_33 ) ;
V_52 = 0 ;
V_63 += V_53 ;
}
}
} else {
if ( V_63 < V_41 ) {
T_4 V_65 ;
V_59 [ 0 ] = ( char ) V_8 -> V_39 ;
V_59 [ 1 ] = ( char ) V_8 -> V_40 ;
F_25 ( V_8 , V_59 + 2 ) ;
V_60 += V_63 ;
V_61 += V_63 ;
if ( V_61 > V_64 ) {
V_61 = V_64 ;
V_62 = V_61 - V_63 ;
}
V_65 = V_41 ;
if ( V_65 > V_61 )
V_65 = V_61 ;
V_61 -= V_65 ;
V_63 = V_41 ;
V_59 = V_56 + V_41 ;
} else if ( V_63 & 1 ) {
V_60 ++ ;
if ( V_61 < V_64 )
V_61 ++ ;
else
V_62 -- ;
}
if ( V_61 > 0 ) {
unsigned short * V_66 = ( unsigned short * ) V_59 ;
V_63 -= V_41 ;
V_63 /= 2 ;
V_52 = V_63 % V_53 ;
V_54 = F_23 ( V_8 , V_63 , V_33 ) ;
V_63 += V_53 - V_52 ;
V_61 = ( V_61 + 1 ) >> 1 ;
while ( V_61 ) {
* V_66 ++ = F_24 ( V_8 , V_54 ++ ) ;
V_61 -- ;
if ( ++ V_52 == V_53 ) {
V_54 = F_23 ( V_8 , V_63 , V_33 ) ;
V_52 = 0 ;
V_63 += V_53 ;
}
}
}
}
F_20 () ;
V_55 = F_26 ( V_46 , V_60 , V_62 ) ;
F_19 () ;
if ( V_55 ) {
V_51 += ( V_62 - V_55 ) ;
V_55 = - V_67 ;
break;
}
V_46 += V_62 ;
V_49 += V_62 ;
V_51 += V_62 ;
V_47 -= V_62 ;
}
* V_48 += V_51 ;
if ( V_51 )
V_55 = V_51 ;
V_58:
F_20 () ;
F_27 ( ( unsigned long ) V_56 ) ;
return V_55 ;
}
static T_2
F_28 ( struct V_24 * V_24 , const char T_3 * V_46 , T_4 V_47 , T_1 * V_48 )
{
struct V_32 * V_32 = V_24 -> V_27 . V_28 -> V_29 ;
unsigned int V_12 = F_10 ( V_32 ) ;
struct V_7 * V_8 ;
long V_49 ;
long V_50 , V_36 , V_68 ;
char * V_59 ;
int V_52 , V_53 , V_33 ;
T_5 * V_69 = NULL , * V_54 = NULL ;
T_4 V_55 ;
char * V_56 ;
V_56 = ( char * ) F_22 ( V_26 ) ;
if ( ! V_56 )
return - V_57 ;
V_49 = * V_48 ;
F_19 () ;
V_50 = ( V_12 & 128 ) ;
V_55 = - V_38 ;
V_8 = F_15 ( V_32 , & V_33 ) ;
if ( ! V_8 )
goto V_58;
V_36 = F_17 ( V_32 ) ;
V_55 = - V_44 ;
if ( V_49 < 0 || V_49 > V_36 )
goto V_58;
if ( V_47 > V_36 - V_49 )
V_47 = V_36 - V_49 ;
V_68 = 0 ;
while ( V_47 ) {
long V_61 = V_47 ;
T_4 V_62 ;
long V_63 ;
if ( V_61 > V_64 )
V_61 = V_64 ;
F_20 () ;
V_55 = F_29 ( V_56 , V_46 , V_61 ) ;
F_19 () ;
if ( V_55 ) {
V_61 -= V_55 ;
if ( ! V_61 ) {
if ( V_68 )
break;
V_55 = - V_67 ;
goto V_58;
}
}
V_36 = F_17 ( V_32 ) ;
if ( V_36 < 0 ) {
if ( V_68 )
break;
V_55 = V_36 ;
goto V_58;
}
if ( V_49 >= V_36 )
break;
if ( V_61 > V_36 - V_49 )
V_61 = V_36 - V_49 ;
V_59 = V_56 ;
V_62 = V_61 ;
V_53 = V_8 -> V_40 ;
V_63 = V_49 ;
if ( ! V_50 ) {
V_69 = V_54 = F_23 ( V_8 , V_63 , V_33 ) ;
V_52 = V_63 % V_53 ;
V_63 += V_53 - V_52 ;
while ( V_61 > 0 ) {
unsigned char V_70 = * V_59 ++ ;
V_61 -- ;
F_30 ( V_8 ,
( F_24 ( V_8 , V_54 ) & 0xff00 ) | V_70 , V_54 ) ;
V_54 ++ ;
if ( ++ V_52 == V_53 ) {
V_54 = F_23 ( V_8 , V_63 , V_33 ) ;
V_52 = 0 ;
V_63 += V_53 ;
}
}
} else {
if ( V_63 < V_41 ) {
char V_71 [ V_41 ] ;
F_25 ( V_8 , V_71 + 2 ) ;
while ( V_63 < V_41 && V_61 > 0 ) {
V_61 -- ;
V_71 [ V_63 ++ ] = * V_59 ++ ;
}
if ( ! V_33 )
F_31 ( V_8 , V_71 + 2 ) ;
}
V_63 -= V_41 ;
V_52 = ( V_63 / 2 ) % V_53 ;
if ( V_61 > 0 ) {
V_69 = V_54 = F_23 ( V_8 , V_63 / 2 , V_33 ) ;
if ( ( V_63 & 1 ) && V_61 > 0 ) {
char V_70 ;
V_61 -- ;
V_70 = * V_59 ++ ;
#ifdef F_32
F_30 ( V_8 , V_70 |
( F_24 ( V_8 , V_54 ) & 0xff00 ) , V_54 ) ;
#else
F_30 ( V_8 , ( V_70 << 8 ) |
( F_24 ( V_8 , V_54 ) & 0xff ) , V_54 ) ;
#endif
V_54 ++ ;
V_63 ++ ;
if ( ++ V_52 == V_53 ) {
V_54 = F_23 ( V_8 , V_63 / 2 , V_33 ) ;
V_52 = 0 ;
}
}
V_63 /= 2 ;
V_63 += V_53 - V_52 ;
}
while ( V_61 > 1 ) {
unsigned short V_72 ;
V_72 = F_33 ( ( ( unsigned short * ) V_59 ) ) ;
F_30 ( V_8 , V_72 , V_54 ++ ) ;
V_59 += 2 ;
V_61 -= 2 ;
if ( ++ V_52 == V_53 ) {
V_54 = F_23 ( V_8 , V_63 , V_33 ) ;
V_52 = 0 ;
V_63 += V_53 ;
}
}
if ( V_61 > 0 ) {
unsigned char V_70 ;
V_70 = * V_59 ++ ;
#ifdef F_32
F_30 ( V_8 , ( F_24 ( V_8 , V_54 ) & 0xff ) | ( V_70 << 8 ) , V_54 ) ;
#else
F_30 ( V_8 , ( F_24 ( V_8 , V_54 ) & 0xff00 ) | V_70 , V_54 ) ;
#endif
}
}
V_47 -= V_62 ;
V_68 += V_62 ;
V_46 += V_62 ;
V_49 += V_62 ;
if ( V_69 )
F_34 ( V_8 , ( unsigned long ) ( V_69 ) , V_54 - V_69 ) ;
}
* V_48 += V_68 ;
V_55 = V_68 ;
if ( V_68 )
F_35 ( V_8 ) ;
V_58:
F_20 () ;
F_27 ( ( unsigned long ) V_56 ) ;
return V_55 ;
}
static unsigned int
F_36 ( struct V_24 * V_24 , T_6 * V_73 )
{
struct V_9 * V_10 = F_8 ( V_24 ) ;
int V_55 = V_74 | V_75 | V_76 ;
if ( V_10 ) {
F_37 ( V_24 , & V_10 -> V_19 , V_73 ) ;
if ( V_10 -> V_18 )
V_55 = V_74 ;
}
return V_55 ;
}
static int
F_38 ( int V_77 , struct V_24 * V_24 , int V_78 )
{
struct V_9 * V_10 = V_24 -> V_25 ;
if ( ! V_10 ) {
if ( ! V_78 )
return 0 ;
V_10 = F_8 ( V_24 ) ;
if ( ! V_10 )
return - V_57 ;
}
return F_39 ( V_77 , V_24 , V_78 , & V_10 -> V_20 ) ;
}
static int
F_40 ( struct V_32 * V_32 , struct V_24 * V_79 )
{
unsigned int V_12 = F_10 ( V_32 ) & 127 ;
int V_55 = 0 ;
F_41 () ;
if( V_12 && ! F_42 ( V_12 - 1 ) )
V_55 = - V_38 ;
F_43 () ;
return V_55 ;
}
static int F_44 ( struct V_32 * V_32 , struct V_24 * V_24 )
{
struct V_9 * V_10 = V_24 -> V_25 ;
if ( V_10 )
F_5 ( V_10 ) ;
return 0 ;
}
void F_45 ( int V_80 )
{
F_46 ( V_81 , NULL , F_47 ( V_82 , V_80 + 1 ) , NULL ,
L_1 , V_80 + 1 ) ;
F_46 ( V_81 , NULL , F_47 ( V_82 , V_80 + 129 ) , NULL ,
L_2 , V_80 + 1 ) ;
}
void F_48 ( int V_80 )
{
F_49 ( V_81 , F_47 ( V_82 , V_80 + 1 ) ) ;
F_49 ( V_81 , F_47 ( V_82 , V_80 + 129 ) ) ;
}
int T_7 F_50 ( void )
{
unsigned int V_83 ;
if ( F_51 ( V_82 , L_3 , & V_84 ) )
F_52 ( L_4 , V_82 ) ;
V_81 = F_53 ( V_85 , L_5 ) ;
F_46 ( V_81 , NULL , F_47 ( V_82 , 0 ) , NULL , L_3 ) ;
F_46 ( V_81 , NULL , F_47 ( V_82 , 128 ) , NULL , L_6 ) ;
for ( V_83 = 0 ; V_83 < V_86 ; V_83 ++ )
F_45 ( V_83 ) ;
return 0 ;
}
