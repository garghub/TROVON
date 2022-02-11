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
struct V_9 * V_10 = V_24 -> V_25 , * V_26 = NULL ;
if ( V_10 )
return V_10 ;
V_10 = F_9 ( sizeof( * V_10 ) , V_27 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_13 = F_10 ( F_11 ( V_24 ) ) & 127 ;
F_12 ( & V_10 -> V_19 ) ;
V_10 -> V_11 . V_28 = F_1 ;
if ( F_13 ( & V_10 -> V_11 ) != 0 ) {
F_7 ( V_10 ) ;
return NULL ;
}
F_14 ( & V_24 -> V_29 ) ;
if ( ! V_24 -> V_25 ) {
V_24 -> V_25 = V_10 ;
} else {
V_26 = V_10 ;
V_10 = V_24 -> V_25 ;
}
F_15 ( & V_24 -> V_29 ) ;
if ( V_26 )
F_5 ( V_26 ) ;
return V_10 ;
}
static struct V_7 *
F_16 ( struct V_30 * V_30 , int * V_31 )
{
unsigned int V_12 = F_10 ( V_30 ) & 127 ;
F_17 () ;
if ( V_12 == 0 ) {
V_12 = V_16 ;
if ( V_31 )
* V_31 = 1 ;
} else {
V_12 -- ;
if ( V_31 )
* V_31 = 0 ;
}
return V_32 [ V_12 ] . V_33 ;
}
static int
F_18 ( struct V_30 * V_30 )
{
int V_34 ;
int V_35 = F_10 ( V_30 ) ;
struct V_7 * V_8 ;
F_17 () ;
V_8 = F_16 ( V_30 , NULL ) ;
if ( ! V_8 )
return - V_36 ;
V_34 = V_8 -> V_37 * V_8 -> V_38 ;
if ( V_35 & 128 )
V_34 = 2 * V_34 + V_39 ;
return V_34 ;
}
static T_1 F_19 ( struct V_24 * V_24 , T_1 V_40 , int V_41 )
{
int V_34 ;
F_20 () ;
V_34 = F_18 ( F_11 ( V_24 ) ) ;
F_21 () ;
if ( V_34 < 0 )
return V_34 ;
switch ( V_41 ) {
default:
return - V_42 ;
case 2 :
V_40 += V_34 ;
break;
case 1 :
V_40 += V_24 -> V_43 ;
case 0 :
break;
}
if ( V_40 < 0 || V_40 > V_34 ) {
return - V_42 ;
}
V_24 -> V_43 = V_40 ;
return V_24 -> V_43 ;
}
static T_2
F_22 ( struct V_24 * V_24 , char T_3 * V_44 , T_4 V_45 , T_1 * V_46 )
{
struct V_30 * V_30 = F_11 ( V_24 ) ;
unsigned int V_12 = F_10 ( V_30 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
long V_47 ;
long V_48 , V_49 ;
int V_50 , V_51 , V_31 ;
unsigned short * V_52 = NULL ;
T_2 V_53 ;
char * V_54 ;
V_54 = ( char * ) F_23 ( V_27 ) ;
if ( ! V_54 )
return - V_55 ;
V_47 = * V_46 ;
F_20 () ;
V_48 = ( V_12 & 128 ) ;
V_53 = - V_36 ;
V_8 = F_16 ( V_30 , & V_31 ) ;
if ( ! V_8 )
goto V_56;
V_53 = - V_42 ;
if ( V_47 < 0 )
goto V_56;
V_10 = V_24 -> V_25 ;
if ( V_45 && V_10 )
V_10 -> V_18 = true ;
V_49 = 0 ;
V_53 = 0 ;
while ( V_45 ) {
char * V_57 , * V_58 ;
long V_59 , V_34 ;
T_2 V_60 ;
long V_61 = V_47 ;
V_34 = F_18 ( V_30 ) ;
if ( V_34 < 0 ) {
if ( V_49 )
break;
V_53 = V_34 ;
goto V_56;
}
if ( V_47 >= V_34 )
break;
if ( V_45 > V_34 - V_47 )
V_45 = V_34 - V_47 ;
V_59 = V_45 ;
if ( V_59 > V_62 )
V_59 = V_62 ;
V_58 = V_57 = V_54 ;
V_60 = V_59 ;
V_51 = V_8 -> V_38 ;
if ( ! V_48 ) {
V_52 = F_24 ( V_8 , V_61 , V_31 ) ;
V_50 = V_61 % V_51 ;
V_61 += V_51 - V_50 ;
while ( V_59 -- > 0 ) {
* V_57 ++ = ( F_25 ( V_8 , V_52 ++ ) & 0xff ) ;
if ( ++ V_50 == V_51 ) {
V_52 = F_24 ( V_8 , V_61 , V_31 ) ;
V_50 = 0 ;
V_61 += V_51 ;
}
}
} else {
if ( V_61 < V_39 ) {
T_4 V_63 ;
V_57 [ 0 ] = ( char ) V_8 -> V_37 ;
V_57 [ 1 ] = ( char ) V_8 -> V_38 ;
F_26 ( V_8 , V_57 + 2 ) ;
V_58 += V_61 ;
V_59 += V_61 ;
if ( V_59 > V_62 ) {
V_59 = V_62 ;
V_60 = V_59 - V_61 ;
}
V_63 = V_39 ;
if ( V_63 > V_59 )
V_63 = V_59 ;
V_59 -= V_63 ;
V_61 = V_39 ;
V_57 = V_54 + V_39 ;
} else if ( V_61 & 1 ) {
V_58 ++ ;
if ( V_59 < V_62 )
V_59 ++ ;
else
V_60 -- ;
}
if ( V_59 > 0 ) {
unsigned short * V_64 = ( unsigned short * ) V_57 ;
V_61 -= V_39 ;
V_61 /= 2 ;
V_50 = V_61 % V_51 ;
V_52 = F_24 ( V_8 , V_61 , V_31 ) ;
V_61 += V_51 - V_50 ;
V_59 = ( V_59 + 1 ) >> 1 ;
while ( V_59 ) {
* V_64 ++ = F_25 ( V_8 , V_52 ++ ) ;
V_59 -- ;
if ( ++ V_50 == V_51 ) {
V_52 = F_24 ( V_8 , V_61 , V_31 ) ;
V_50 = 0 ;
V_61 += V_51 ;
}
}
}
}
F_21 () ;
V_53 = F_27 ( V_44 , V_58 , V_60 ) ;
F_20 () ;
if ( V_53 ) {
V_49 += ( V_60 - V_53 ) ;
V_53 = - V_65 ;
break;
}
V_44 += V_60 ;
V_47 += V_60 ;
V_49 += V_60 ;
V_45 -= V_60 ;
}
* V_46 += V_49 ;
if ( V_49 )
V_53 = V_49 ;
V_56:
F_21 () ;
F_28 ( ( unsigned long ) V_54 ) ;
return V_53 ;
}
static T_2
F_29 ( struct V_24 * V_24 , const char T_3 * V_44 , T_4 V_45 , T_1 * V_46 )
{
struct V_30 * V_30 = F_11 ( V_24 ) ;
unsigned int V_12 = F_10 ( V_30 ) ;
struct V_7 * V_8 ;
long V_47 ;
long V_48 , V_34 , V_66 ;
char * V_57 ;
int V_50 , V_51 , V_31 ;
T_5 * V_67 = NULL , * V_52 = NULL ;
T_4 V_53 ;
char * V_54 ;
V_54 = ( char * ) F_23 ( V_27 ) ;
if ( ! V_54 )
return - V_55 ;
V_47 = * V_46 ;
F_20 () ;
V_48 = ( V_12 & 128 ) ;
V_53 = - V_36 ;
V_8 = F_16 ( V_30 , & V_31 ) ;
if ( ! V_8 )
goto V_56;
V_34 = F_18 ( V_30 ) ;
V_53 = - V_42 ;
if ( V_47 < 0 || V_47 > V_34 )
goto V_56;
if ( V_45 > V_34 - V_47 )
V_45 = V_34 - V_47 ;
V_66 = 0 ;
while ( V_45 ) {
long V_59 = V_45 ;
T_4 V_60 ;
long V_61 ;
if ( V_59 > V_62 )
V_59 = V_62 ;
F_21 () ;
V_53 = F_30 ( V_54 , V_44 , V_59 ) ;
F_20 () ;
if ( V_53 ) {
V_59 -= V_53 ;
if ( ! V_59 ) {
if ( V_66 )
break;
V_53 = - V_65 ;
goto V_56;
}
}
V_34 = F_18 ( V_30 ) ;
if ( V_34 < 0 ) {
if ( V_66 )
break;
V_53 = V_34 ;
goto V_56;
}
if ( V_47 >= V_34 )
break;
if ( V_59 > V_34 - V_47 )
V_59 = V_34 - V_47 ;
V_57 = V_54 ;
V_60 = V_59 ;
V_51 = V_8 -> V_38 ;
V_61 = V_47 ;
if ( ! V_48 ) {
V_67 = V_52 = F_24 ( V_8 , V_61 , V_31 ) ;
V_50 = V_61 % V_51 ;
V_61 += V_51 - V_50 ;
while ( V_59 > 0 ) {
unsigned char V_68 = * V_57 ++ ;
V_59 -- ;
F_31 ( V_8 ,
( F_25 ( V_8 , V_52 ) & 0xff00 ) | V_68 , V_52 ) ;
V_52 ++ ;
if ( ++ V_50 == V_51 ) {
V_52 = F_24 ( V_8 , V_61 , V_31 ) ;
V_50 = 0 ;
V_61 += V_51 ;
}
}
} else {
if ( V_61 < V_39 ) {
char V_69 [ V_39 ] ;
F_26 ( V_8 , V_69 + 2 ) ;
while ( V_61 < V_39 && V_59 > 0 ) {
V_59 -- ;
V_69 [ V_61 ++ ] = * V_57 ++ ;
}
if ( ! V_31 )
F_32 ( V_8 , V_69 + 2 ) ;
}
V_61 -= V_39 ;
V_50 = ( V_61 / 2 ) % V_51 ;
if ( V_59 > 0 ) {
V_67 = V_52 = F_24 ( V_8 , V_61 / 2 , V_31 ) ;
if ( ( V_61 & 1 ) && V_59 > 0 ) {
char V_68 ;
V_59 -- ;
V_68 = * V_57 ++ ;
#ifdef F_33
F_31 ( V_8 , V_68 |
( F_25 ( V_8 , V_52 ) & 0xff00 ) , V_52 ) ;
#else
F_31 ( V_8 , ( V_68 << 8 ) |
( F_25 ( V_8 , V_52 ) & 0xff ) , V_52 ) ;
#endif
V_52 ++ ;
V_61 ++ ;
if ( ++ V_50 == V_51 ) {
V_52 = F_24 ( V_8 , V_61 / 2 , V_31 ) ;
V_50 = 0 ;
}
}
V_61 /= 2 ;
V_61 += V_51 - V_50 ;
}
while ( V_59 > 1 ) {
unsigned short V_70 ;
V_70 = F_34 ( ( ( unsigned short * ) V_57 ) ) ;
F_31 ( V_8 , V_70 , V_52 ++ ) ;
V_57 += 2 ;
V_59 -= 2 ;
if ( ++ V_50 == V_51 ) {
V_52 = F_24 ( V_8 , V_61 , V_31 ) ;
V_50 = 0 ;
V_61 += V_51 ;
}
}
if ( V_59 > 0 ) {
unsigned char V_68 ;
V_68 = * V_57 ++ ;
#ifdef F_33
F_31 ( V_8 , ( F_25 ( V_8 , V_52 ) & 0xff ) | ( V_68 << 8 ) , V_52 ) ;
#else
F_31 ( V_8 , ( F_25 ( V_8 , V_52 ) & 0xff00 ) | V_68 , V_52 ) ;
#endif
}
}
V_45 -= V_60 ;
V_66 += V_60 ;
V_44 += V_60 ;
V_47 += V_60 ;
if ( V_67 )
F_35 ( V_8 , ( unsigned long ) ( V_67 ) , V_52 - V_67 ) ;
}
* V_46 += V_66 ;
V_53 = V_66 ;
if ( V_66 )
F_36 ( V_8 ) ;
V_56:
F_21 () ;
F_28 ( ( unsigned long ) V_54 ) ;
return V_53 ;
}
static unsigned int
F_37 ( struct V_24 * V_24 , T_6 * V_71 )
{
struct V_9 * V_10 = F_8 ( V_24 ) ;
int V_53 = V_72 | V_73 | V_74 ;
if ( V_10 ) {
F_38 ( V_24 , & V_10 -> V_19 , V_71 ) ;
if ( V_10 -> V_18 )
V_53 = V_72 ;
}
return V_53 ;
}
static int
F_39 ( int V_75 , struct V_24 * V_24 , int V_76 )
{
struct V_9 * V_10 = V_24 -> V_25 ;
if ( ! V_10 ) {
if ( ! V_76 )
return 0 ;
V_10 = F_8 ( V_24 ) ;
if ( ! V_10 )
return - V_55 ;
}
return F_40 ( V_75 , V_24 , V_76 , & V_10 -> V_20 ) ;
}
static int
F_41 ( struct V_30 * V_30 , struct V_24 * V_77 )
{
unsigned int V_12 = F_10 ( V_30 ) & 127 ;
int V_53 = 0 ;
F_20 () ;
if( V_12 && ! F_42 ( V_12 - 1 ) )
V_53 = - V_36 ;
F_21 () ;
return V_53 ;
}
static int F_43 ( struct V_30 * V_30 , struct V_24 * V_24 )
{
struct V_9 * V_10 = V_24 -> V_25 ;
if ( V_10 )
F_5 ( V_10 ) ;
return 0 ;
}
void F_44 ( int V_78 )
{
F_45 ( V_79 , NULL , F_46 ( V_80 , V_78 + 1 ) , NULL ,
L_1 , V_78 + 1 ) ;
F_45 ( V_79 , NULL , F_46 ( V_80 , V_78 + 129 ) , NULL ,
L_2 , V_78 + 1 ) ;
}
void F_47 ( int V_78 )
{
F_48 ( V_79 , F_46 ( V_80 , V_78 + 1 ) ) ;
F_48 ( V_79 , F_46 ( V_80 , V_78 + 129 ) ) ;
}
int T_7 F_49 ( void )
{
unsigned int V_81 ;
if ( F_50 ( V_80 , L_3 , & V_82 ) )
F_51 ( L_4 , V_80 ) ;
V_79 = F_52 ( V_83 , L_5 ) ;
F_45 ( V_79 , NULL , F_46 ( V_80 , 0 ) , NULL , L_3 ) ;
F_45 ( V_79 , NULL , F_46 ( V_80 , 128 ) , NULL , L_6 ) ;
for ( V_81 = 0 ; V_81 < V_84 ; V_81 ++ )
F_44 ( V_81 ) ;
return 0 ;
}
