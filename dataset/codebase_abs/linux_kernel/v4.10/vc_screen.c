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
return F_22 ( V_24 , V_40 , V_41 , V_34 ) ;
}
static T_2
F_23 ( struct V_24 * V_24 , char T_3 * V_42 , T_4 V_43 , T_1 * V_44 )
{
struct V_30 * V_30 = F_11 ( V_24 ) ;
unsigned int V_12 = F_10 ( V_30 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
long V_45 ;
long V_46 , V_47 ;
int V_48 , V_49 , V_31 ;
unsigned short * V_50 = NULL ;
T_2 V_51 ;
char * V_52 ;
V_52 = ( char * ) F_24 ( V_27 ) ;
if ( ! V_52 )
return - V_53 ;
V_45 = * V_44 ;
F_20 () ;
V_46 = ( V_12 & 128 ) ;
V_51 = - V_36 ;
V_8 = F_16 ( V_30 , & V_31 ) ;
if ( ! V_8 )
goto V_54;
V_51 = - V_55 ;
if ( V_45 < 0 )
goto V_54;
V_10 = V_24 -> V_25 ;
if ( V_43 && V_10 )
V_10 -> V_18 = true ;
V_47 = 0 ;
V_51 = 0 ;
while ( V_43 ) {
char * V_56 , * V_57 ;
long V_58 , V_34 ;
T_2 V_59 ;
long V_60 = V_45 ;
V_34 = F_18 ( V_30 ) ;
if ( V_34 < 0 ) {
if ( V_47 )
break;
V_51 = V_34 ;
goto V_54;
}
if ( V_45 >= V_34 )
break;
if ( V_43 > V_34 - V_45 )
V_43 = V_34 - V_45 ;
V_58 = V_43 ;
if ( V_58 > V_61 )
V_58 = V_61 ;
V_57 = V_56 = V_52 ;
V_59 = V_58 ;
V_49 = V_8 -> V_38 ;
if ( ! V_46 ) {
V_50 = F_25 ( V_8 , V_60 , V_31 ) ;
V_48 = V_60 % V_49 ;
V_60 += V_49 - V_48 ;
while ( V_58 -- > 0 ) {
* V_56 ++ = ( F_26 ( V_8 , V_50 ++ ) & 0xff ) ;
if ( ++ V_48 == V_49 ) {
V_50 = F_25 ( V_8 , V_60 , V_31 ) ;
V_48 = 0 ;
V_60 += V_49 ;
}
}
} else {
if ( V_60 < V_39 ) {
T_4 V_62 ;
V_56 [ 0 ] = ( char ) V_8 -> V_37 ;
V_56 [ 1 ] = ( char ) V_8 -> V_38 ;
F_27 ( V_8 , V_56 + 2 ) ;
V_57 += V_60 ;
V_58 += V_60 ;
if ( V_58 > V_61 ) {
V_58 = V_61 ;
V_59 = V_58 - V_60 ;
}
V_62 = V_39 ;
if ( V_62 > V_58 )
V_62 = V_58 ;
V_58 -= V_62 ;
V_60 = V_39 ;
V_56 = V_52 + V_39 ;
} else if ( V_60 & 1 ) {
V_57 ++ ;
if ( V_58 < V_61 )
V_58 ++ ;
else
V_59 -- ;
}
if ( V_58 > 0 ) {
unsigned short * V_63 = ( unsigned short * ) V_56 ;
V_60 -= V_39 ;
V_60 /= 2 ;
V_48 = V_60 % V_49 ;
V_50 = F_25 ( V_8 , V_60 , V_31 ) ;
V_60 += V_49 - V_48 ;
V_58 = ( V_58 + 1 ) >> 1 ;
while ( V_58 ) {
* V_63 ++ = F_26 ( V_8 , V_50 ++ ) ;
V_58 -- ;
if ( ++ V_48 == V_49 ) {
V_50 = F_25 ( V_8 , V_60 , V_31 ) ;
V_48 = 0 ;
V_60 += V_49 ;
}
}
}
}
F_21 () ;
V_51 = F_28 ( V_42 , V_57 , V_59 ) ;
F_20 () ;
if ( V_51 ) {
V_47 += ( V_59 - V_51 ) ;
V_51 = - V_64 ;
break;
}
V_42 += V_59 ;
V_45 += V_59 ;
V_47 += V_59 ;
V_43 -= V_59 ;
}
* V_44 += V_47 ;
if ( V_47 )
V_51 = V_47 ;
V_54:
F_21 () ;
F_29 ( ( unsigned long ) V_52 ) ;
return V_51 ;
}
static T_2
F_30 ( struct V_24 * V_24 , const char T_3 * V_42 , T_4 V_43 , T_1 * V_44 )
{
struct V_30 * V_30 = F_11 ( V_24 ) ;
unsigned int V_12 = F_10 ( V_30 ) ;
struct V_7 * V_8 ;
long V_45 ;
long V_46 , V_34 , V_65 ;
char * V_56 ;
int V_48 , V_49 , V_31 ;
T_5 * V_66 = NULL , * V_50 = NULL ;
T_4 V_51 ;
char * V_52 ;
V_52 = ( char * ) F_24 ( V_27 ) ;
if ( ! V_52 )
return - V_53 ;
V_45 = * V_44 ;
F_20 () ;
V_46 = ( V_12 & 128 ) ;
V_51 = - V_36 ;
V_8 = F_16 ( V_30 , & V_31 ) ;
if ( ! V_8 )
goto V_54;
V_34 = F_18 ( V_30 ) ;
V_51 = - V_55 ;
if ( V_45 < 0 || V_45 > V_34 )
goto V_54;
if ( V_43 > V_34 - V_45 )
V_43 = V_34 - V_45 ;
V_65 = 0 ;
while ( V_43 ) {
long V_58 = V_43 ;
T_4 V_59 ;
long V_60 ;
if ( V_58 > V_61 )
V_58 = V_61 ;
F_21 () ;
V_51 = F_31 ( V_52 , V_42 , V_58 ) ;
F_20 () ;
if ( V_51 ) {
V_58 -= V_51 ;
if ( ! V_58 ) {
if ( V_65 )
break;
V_51 = - V_64 ;
goto V_54;
}
}
V_34 = F_18 ( V_30 ) ;
if ( V_34 < 0 ) {
if ( V_65 )
break;
V_51 = V_34 ;
goto V_54;
}
if ( V_45 >= V_34 )
break;
if ( V_58 > V_34 - V_45 )
V_58 = V_34 - V_45 ;
V_56 = V_52 ;
V_59 = V_58 ;
V_49 = V_8 -> V_38 ;
V_60 = V_45 ;
if ( ! V_46 ) {
V_66 = V_50 = F_25 ( V_8 , V_60 , V_31 ) ;
V_48 = V_60 % V_49 ;
V_60 += V_49 - V_48 ;
while ( V_58 > 0 ) {
unsigned char V_67 = * V_56 ++ ;
V_58 -- ;
F_32 ( V_8 ,
( F_26 ( V_8 , V_50 ) & 0xff00 ) | V_67 , V_50 ) ;
V_50 ++ ;
if ( ++ V_48 == V_49 ) {
V_50 = F_25 ( V_8 , V_60 , V_31 ) ;
V_48 = 0 ;
V_60 += V_49 ;
}
}
} else {
if ( V_60 < V_39 ) {
char V_68 [ V_39 ] ;
F_27 ( V_8 , V_68 + 2 ) ;
while ( V_60 < V_39 && V_58 > 0 ) {
V_58 -- ;
V_68 [ V_60 ++ ] = * V_56 ++ ;
}
if ( ! V_31 )
F_33 ( V_8 , V_68 + 2 ) ;
}
V_60 -= V_39 ;
V_48 = ( V_60 / 2 ) % V_49 ;
if ( V_58 > 0 ) {
V_66 = V_50 = F_25 ( V_8 , V_60 / 2 , V_31 ) ;
if ( ( V_60 & 1 ) && V_58 > 0 ) {
char V_67 ;
V_58 -- ;
V_67 = * V_56 ++ ;
#ifdef F_34
F_32 ( V_8 , V_67 |
( F_26 ( V_8 , V_50 ) & 0xff00 ) , V_50 ) ;
#else
F_32 ( V_8 , ( V_67 << 8 ) |
( F_26 ( V_8 , V_50 ) & 0xff ) , V_50 ) ;
#endif
V_50 ++ ;
V_60 ++ ;
if ( ++ V_48 == V_49 ) {
V_50 = F_25 ( V_8 , V_60 / 2 , V_31 ) ;
V_48 = 0 ;
}
}
V_60 /= 2 ;
V_60 += V_49 - V_48 ;
}
while ( V_58 > 1 ) {
unsigned short V_69 ;
V_69 = F_35 ( ( ( unsigned short * ) V_56 ) ) ;
F_32 ( V_8 , V_69 , V_50 ++ ) ;
V_56 += 2 ;
V_58 -= 2 ;
if ( ++ V_48 == V_49 ) {
V_50 = F_25 ( V_8 , V_60 , V_31 ) ;
V_48 = 0 ;
V_60 += V_49 ;
}
}
if ( V_58 > 0 ) {
unsigned char V_67 ;
V_67 = * V_56 ++ ;
#ifdef F_34
F_32 ( V_8 , ( F_26 ( V_8 , V_50 ) & 0xff ) | ( V_67 << 8 ) , V_50 ) ;
#else
F_32 ( V_8 , ( F_26 ( V_8 , V_50 ) & 0xff00 ) | V_67 , V_50 ) ;
#endif
}
}
V_43 -= V_59 ;
V_65 += V_59 ;
V_42 += V_59 ;
V_45 += V_59 ;
if ( V_66 )
F_36 ( V_8 , ( unsigned long ) ( V_66 ) , V_50 - V_66 ) ;
}
* V_44 += V_65 ;
V_51 = V_65 ;
if ( V_65 )
F_37 ( V_8 ) ;
V_54:
F_21 () ;
F_29 ( ( unsigned long ) V_52 ) ;
return V_51 ;
}
static unsigned int
F_38 ( struct V_24 * V_24 , T_6 * V_70 )
{
struct V_9 * V_10 = F_8 ( V_24 ) ;
int V_51 = V_71 | V_72 | V_73 ;
if ( V_10 ) {
F_39 ( V_24 , & V_10 -> V_19 , V_70 ) ;
if ( V_10 -> V_18 )
V_51 = V_71 ;
}
return V_51 ;
}
static int
F_40 ( int V_74 , struct V_24 * V_24 , int V_75 )
{
struct V_9 * V_10 = V_24 -> V_25 ;
if ( ! V_10 ) {
if ( ! V_75 )
return 0 ;
V_10 = F_8 ( V_24 ) ;
if ( ! V_10 )
return - V_53 ;
}
return F_41 ( V_74 , V_24 , V_75 , & V_10 -> V_20 ) ;
}
static int
F_42 ( struct V_30 * V_30 , struct V_24 * V_76 )
{
unsigned int V_12 = F_10 ( V_30 ) & 127 ;
int V_51 = 0 ;
F_20 () ;
if( V_12 && ! F_43 ( V_12 - 1 ) )
V_51 = - V_36 ;
F_21 () ;
return V_51 ;
}
static int F_44 ( struct V_30 * V_30 , struct V_24 * V_24 )
{
struct V_9 * V_10 = V_24 -> V_25 ;
if ( V_10 )
F_5 ( V_10 ) ;
return 0 ;
}
void F_45 ( int V_77 )
{
F_46 ( V_78 , NULL , F_47 ( V_79 , V_77 + 1 ) , NULL ,
L_1 , V_77 + 1 ) ;
F_46 ( V_78 , NULL , F_47 ( V_79 , V_77 + 129 ) , NULL ,
L_2 , V_77 + 1 ) ;
}
void F_48 ( int V_77 )
{
F_49 ( V_78 , F_47 ( V_79 , V_77 + 1 ) ) ;
F_49 ( V_78 , F_47 ( V_79 , V_77 + 129 ) ) ;
}
int T_7 F_50 ( void )
{
unsigned int V_80 ;
if ( F_51 ( V_79 , L_3 , & V_81 ) )
F_52 ( L_4 , V_79 ) ;
V_78 = F_53 ( V_82 , L_5 ) ;
F_46 ( V_78 , NULL , F_47 ( V_79 , 0 ) , NULL , L_3 ) ;
F_46 ( V_78 , NULL , F_47 ( V_79 , 128 ) , NULL , L_6 ) ;
for ( V_80 = 0 ; V_80 < V_83 ; V_80 ++ )
F_45 ( V_80 ) ;
return 0 ;
}
