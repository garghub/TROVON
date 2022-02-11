static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 , int V_6 , int V_7 )
{
unsigned long V_8 , V_9 ;
int V_10 ;
int V_11 ;
for ( V_8 = V_12 , V_9 = V_8 + V_7 * V_13 , V_10 = 0 ;
F_2 ( V_12 , V_9 ) ; V_10 ++ ) {
if ( V_3 )
V_11 = F_3 ( V_2 , V_5 , V_5 , V_6 ) ;
else
V_11 = F_4 ( V_2 , V_5 , V_5 , V_6 ) ;
if ( V_11 )
return V_11 ;
}
F_5 ( L_1 ,
V_10 , V_7 , ( long ) V_10 * V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 , int V_6 )
{
unsigned long V_14 = 0 ;
int V_11 = 0 ;
int V_15 ;
F_7 () ;
F_8 () ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
if ( V_3 )
V_11 = F_3 ( V_2 , V_5 , V_5 , V_6 ) ;
else
V_11 = F_4 ( V_2 , V_5 , V_5 , V_6 ) ;
if ( V_11 )
goto V_16;
}
for ( V_15 = 0 ; V_15 < 8 ; V_15 ++ ) {
T_1 V_8 , V_9 ;
V_8 = F_9 () ;
if ( V_3 )
V_11 = F_3 ( V_2 , V_5 , V_5 , V_6 ) ;
else
V_11 = F_4 ( V_2 , V_5 , V_5 , V_6 ) ;
V_9 = F_9 () ;
if ( V_11 )
goto V_16;
V_14 += V_9 - V_8 ;
}
V_16:
F_10 () ;
F_11 () ;
if ( V_11 == 0 )
F_5 ( L_2 ,
( V_14 + 4 ) / 8 , V_6 ) ;
return V_11 ;
}
static void F_12 ( const char * V_17 , int V_3 , unsigned int V_7 ,
struct V_18 * V_19 ,
unsigned int V_20 , T_2 * V_21 )
{
unsigned int V_11 , V_15 , V_22 , V_23 ;
const char * V_24 ;
char V_25 [ 128 ] ;
struct V_26 * V_27 ;
struct V_1 V_2 ;
const char * V_28 ;
T_3 * V_29 ;
if ( V_3 == V_30 )
V_28 = L_3 ;
else
V_28 = L_4 ;
F_5 ( L_5 , V_17 , V_28 ) ;
V_27 = F_13 ( V_17 , 0 , V_31 ) ;
if ( F_14 ( V_27 ) ) {
F_5 ( L_6 , V_17 ,
F_15 ( V_27 ) ) ;
return;
}
V_2 . V_27 = V_27 ;
V_2 . V_32 = 0 ;
V_15 = 0 ;
do {
V_29 = V_33 ;
do {
struct V_4 V_5 [ V_34 ] ;
if ( ( * V_21 + * V_29 ) > V_34 * V_35 ) {
F_5 ( L_7
L_8 , * V_21 + * V_29 ,
V_34 * V_35 ) ;
goto V_16;
}
F_5 ( L_9 , V_15 ,
* V_21 * 8 , * V_29 ) ;
memset ( V_36 [ 0 ] , 0xff , V_35 ) ;
V_24 = V_36 [ 0 ] ;
for ( V_22 = 0 ; V_22 < V_20 ; V_22 ++ ) {
if ( V_19 [ V_22 ] . V_37 == * V_21 ) {
V_24 = V_19 [ V_22 ] . V_24 ;
break;
}
}
V_11 = F_16 ( V_27 , V_24 , * V_21 ) ;
if ( V_11 ) {
F_5 ( L_10 ,
F_17 ( V_27 ) ) ;
goto V_16;
}
F_18 ( V_5 , V_34 ) ;
F_19 ( V_5 , V_36 [ 0 ] + * V_21 ,
V_35 - * V_21 ) ;
for ( V_22 = 1 ; V_22 < V_34 ; V_22 ++ ) {
F_19 ( V_5 + V_22 , V_36 [ V_22 ] , V_35 ) ;
memset ( V_36 [ V_22 ] , 0xff , V_35 ) ;
}
V_23 = F_20 ( V_27 ) ;
if ( V_23 ) {
memset ( & V_25 , 0xff , V_23 ) ;
F_21 ( V_27 , V_25 , V_23 ) ;
}
if ( V_7 )
V_11 = F_1 ( & V_2 , V_3 , V_5 ,
* V_29 , V_7 ) ;
else
V_11 = F_6 ( & V_2 , V_3 , V_5 ,
* V_29 ) ;
if ( V_11 ) {
F_5 ( L_11 , V_28 , V_2 . V_32 ) ;
break;
}
V_29 ++ ;
V_15 ++ ;
} while ( * V_29 );
V_21 ++ ;
} while ( * V_21 );
V_16:
F_22 ( V_27 ) ;
}
static int F_23 ( struct V_38 * V_2 ,
struct V_4 * V_5 , int V_6 ,
char * V_16 , int V_7 )
{
unsigned long V_8 , V_9 ;
int V_10 ;
int V_11 ;
for ( V_8 = V_12 , V_9 = V_8 + V_7 * V_13 , V_10 = 0 ;
F_2 ( V_12 , V_9 ) ; V_10 ++ ) {
V_11 = F_24 ( V_2 , V_5 , V_6 , V_16 ) ;
if ( V_11 )
return V_11 ;
}
F_5 ( L_12 ,
V_10 / V_7 , ( ( long ) V_10 * V_6 ) / V_7 ) ;
return 0 ;
}
static int F_25 ( struct V_38 * V_2 , struct V_4 * V_5 ,
int V_6 , int V_39 , char * V_16 , int V_7 )
{
unsigned long V_8 , V_9 ;
int V_10 , V_40 ;
int V_11 ;
if ( V_39 == V_6 )
return F_23 ( V_2 , V_5 , V_6 , V_16 , V_7 ) ;
for ( V_8 = V_12 , V_9 = V_8 + V_7 * V_13 , V_10 = 0 ;
F_2 ( V_12 , V_9 ) ; V_10 ++ ) {
V_11 = F_26 ( V_2 ) ;
if ( V_11 )
return V_11 ;
for ( V_40 = 0 ; V_40 < V_6 ; V_40 += V_39 ) {
V_11 = F_27 ( V_2 , V_5 , V_39 ) ;
if ( V_11 )
return V_11 ;
}
V_11 = F_28 ( V_2 , V_16 ) ;
if ( V_11 )
return V_11 ;
}
F_5 ( L_12 ,
V_10 / V_7 , ( ( long ) V_10 * V_6 ) / V_7 ) ;
return 0 ;
}
static int F_29 ( struct V_38 * V_2 ,
struct V_4 * V_5 , int V_6 , char * V_16 )
{
unsigned long V_14 = 0 ;
int V_15 ;
int V_11 ;
F_7 () ;
F_8 () ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
V_11 = F_24 ( V_2 , V_5 , V_6 , V_16 ) ;
if ( V_11 )
goto V_16;
}
for ( V_15 = 0 ; V_15 < 8 ; V_15 ++ ) {
T_1 V_8 , V_9 ;
V_8 = F_9 () ;
V_11 = F_24 ( V_2 , V_5 , V_6 , V_16 ) ;
if ( V_11 )
goto V_16;
V_9 = F_9 () ;
V_14 += V_9 - V_8 ;
}
V_16:
F_10 () ;
F_11 () ;
if ( V_11 )
return V_11 ;
F_5 ( L_13 ,
V_14 / 8 , V_14 / ( 8 * V_6 ) ) ;
return 0 ;
}
static int F_30 ( struct V_38 * V_2 , struct V_4 * V_5 ,
int V_6 , int V_39 , char * V_16 )
{
unsigned long V_14 = 0 ;
int V_15 , V_40 ;
int V_11 ;
if ( V_39 == V_6 )
return F_29 ( V_2 , V_5 , V_6 , V_16 ) ;
F_7 () ;
F_8 () ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
V_11 = F_26 ( V_2 ) ;
if ( V_11 )
goto V_16;
for ( V_40 = 0 ; V_40 < V_6 ; V_40 += V_39 ) {
V_11 = F_27 ( V_2 , V_5 , V_39 ) ;
if ( V_11 )
goto V_16;
}
V_11 = F_28 ( V_2 , V_16 ) ;
if ( V_11 )
goto V_16;
}
for ( V_15 = 0 ; V_15 < 8 ; V_15 ++ ) {
T_1 V_8 , V_9 ;
V_8 = F_9 () ;
V_11 = F_26 ( V_2 ) ;
if ( V_11 )
goto V_16;
for ( V_40 = 0 ; V_40 < V_6 ; V_40 += V_39 ) {
V_11 = F_27 ( V_2 , V_5 , V_39 ) ;
if ( V_11 )
goto V_16;
}
V_11 = F_28 ( V_2 , V_16 ) ;
if ( V_11 )
goto V_16;
V_9 = F_9 () ;
V_14 += V_9 - V_8 ;
}
V_16:
F_10 () ;
F_11 () ;
if ( V_11 )
return V_11 ;
F_5 ( L_13 ,
V_14 / 8 , V_14 / ( 8 * V_6 ) ) ;
return 0 ;
}
static void F_31 ( struct V_4 * V_5 )
{
int V_15 ;
F_18 ( V_5 , V_34 ) ;
for ( V_15 = 0 ; V_15 < V_34 ; V_15 ++ ) {
F_19 ( V_5 + V_15 , V_36 [ V_15 ] , V_35 ) ;
memset ( V_36 [ V_15 ] , 0xff , V_35 ) ;
}
}
static void F_32 ( const char * V_17 , unsigned int V_7 ,
struct V_41 * V_42 )
{
struct V_4 V_5 [ V_34 ] ;
struct V_43 * V_27 ;
struct V_38 V_2 ;
static char V_44 [ 1024 ] ;
int V_15 ;
int V_11 ;
F_5 ( V_45 L_14 , V_17 ) ;
V_27 = F_33 ( V_17 , 0 , V_31 ) ;
if ( F_14 ( V_27 ) ) {
F_5 ( V_46 L_6 , V_17 ,
F_15 ( V_27 ) ) ;
return;
}
V_2 . V_27 = V_27 ;
V_2 . V_32 = 0 ;
if ( F_34 ( V_27 ) > sizeof( V_44 ) ) {
F_5 ( V_46 L_15 ,
F_34 ( V_27 ) , sizeof( V_44 ) ) ;
goto V_16;
}
F_31 ( V_5 ) ;
for ( V_15 = 0 ; V_42 [ V_15 ] . V_6 != 0 ; V_15 ++ ) {
if ( V_42 [ V_15 ] . V_6 > V_34 * V_35 ) {
F_5 ( V_46
L_16 ,
V_42 [ V_15 ] . V_6 , V_34 * V_35 ) ;
goto V_16;
}
if ( V_42 [ V_15 ] . V_37 )
F_35 ( V_27 , V_36 [ 0 ] , V_42 [ V_15 ] . V_37 ) ;
F_5 ( V_45 L_17
L_18 ,
V_15 , V_42 [ V_15 ] . V_6 , V_42 [ V_15 ] . V_39 , V_42 [ V_15 ] . V_6 / V_42 [ V_15 ] . V_39 ) ;
if ( V_7 )
V_11 = F_25 ( & V_2 , V_5 , V_42 [ V_15 ] . V_6 ,
V_42 [ V_15 ] . V_39 , V_44 , V_7 ) ;
else
V_11 = F_30 ( & V_2 , V_5 , V_42 [ V_15 ] . V_6 ,
V_42 [ V_15 ] . V_39 , V_44 ) ;
if ( V_11 ) {
F_5 ( V_46 L_19 , V_11 ) ;
break;
}
}
V_16:
F_36 ( V_27 ) ;
}
static void F_37 ( struct V_47 * V_48 , int V_49 )
{
struct V_50 * V_51 = V_48 -> V_52 ;
if ( V_49 == - V_53 )
return;
V_51 -> V_49 = V_49 ;
F_38 ( & V_51 -> V_54 ) ;
}
static inline int F_39 ( struct V_55 * V_48 , int V_11 )
{
if ( V_11 == - V_53 || V_11 == - V_56 ) {
struct V_50 * V_57 = V_48 -> V_58 . V_52 ;
V_11 = F_40 ( & V_57 -> V_54 ) ;
if ( ! V_11 )
V_11 = V_57 -> V_49 ;
F_41 ( V_57 -> V_54 ) ;
}
return V_11 ;
}
static int F_42 ( struct V_55 * V_48 , int V_6 ,
char * V_16 , int V_7 )
{
unsigned long V_8 , V_9 ;
int V_10 ;
int V_11 ;
for ( V_8 = V_12 , V_9 = V_8 + V_7 * V_13 , V_10 = 0 ;
F_2 ( V_12 , V_9 ) ; V_10 ++ ) {
V_11 = F_39 ( V_48 , F_43 ( V_48 ) ) ;
if ( V_11 )
return V_11 ;
}
F_5 ( L_12 ,
V_10 / V_7 , ( ( long ) V_10 * V_6 ) / V_7 ) ;
return 0 ;
}
static int F_44 ( struct V_55 * V_48 , int V_6 ,
int V_39 , char * V_16 , int V_7 )
{
unsigned long V_8 , V_9 ;
int V_10 , V_40 ;
int V_11 ;
if ( V_39 == V_6 )
return F_42 ( V_48 , V_6 , V_16 , V_7 ) ;
for ( V_8 = V_12 , V_9 = V_8 + V_7 * V_13 , V_10 = 0 ;
F_2 ( V_12 , V_9 ) ; V_10 ++ ) {
V_11 = F_45 ( V_48 ) ;
if ( V_11 )
return V_11 ;
for ( V_40 = 0 ; V_40 < V_6 ; V_40 += V_39 ) {
V_11 = F_39 ( V_48 , F_46 ( V_48 ) ) ;
if ( V_11 )
return V_11 ;
}
V_11 = F_39 ( V_48 , F_47 ( V_48 ) ) ;
if ( V_11 )
return V_11 ;
}
F_48 ( L_12 ,
V_10 / V_7 , ( ( long ) V_10 * V_6 ) / V_7 ) ;
return 0 ;
}
static int F_49 ( struct V_55 * V_48 , int V_6 ,
char * V_16 )
{
unsigned long V_14 = 0 ;
int V_11 , V_15 ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
V_11 = F_39 ( V_48 , F_43 ( V_48 ) ) ;
if ( V_11 )
goto V_16;
}
for ( V_15 = 0 ; V_15 < 8 ; V_15 ++ ) {
T_1 V_8 , V_9 ;
V_8 = F_9 () ;
V_11 = F_39 ( V_48 , F_43 ( V_48 ) ) ;
if ( V_11 )
goto V_16;
V_9 = F_9 () ;
V_14 += V_9 - V_8 ;
}
V_16:
if ( V_11 )
return V_11 ;
F_48 ( L_13 ,
V_14 / 8 , V_14 / ( 8 * V_6 ) ) ;
return 0 ;
}
static int F_50 ( struct V_55 * V_48 , int V_6 ,
int V_39 , char * V_16 )
{
unsigned long V_14 = 0 ;
int V_15 , V_40 , V_11 ;
if ( V_39 == V_6 )
return F_49 ( V_48 , V_6 , V_16 ) ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
V_11 = F_45 ( V_48 ) ;
if ( V_11 )
goto V_16;
for ( V_40 = 0 ; V_40 < V_6 ; V_40 += V_39 ) {
V_11 = F_39 ( V_48 , F_46 ( V_48 ) ) ;
if ( V_11 )
goto V_16;
}
V_11 = F_39 ( V_48 , F_47 ( V_48 ) ) ;
if ( V_11 )
goto V_16;
}
for ( V_15 = 0 ; V_15 < 8 ; V_15 ++ ) {
T_1 V_8 , V_9 ;
V_8 = F_9 () ;
V_11 = F_45 ( V_48 ) ;
if ( V_11 )
goto V_16;
for ( V_40 = 0 ; V_40 < V_6 ; V_40 += V_39 ) {
V_11 = F_39 ( V_48 , F_46 ( V_48 ) ) ;
if ( V_11 )
goto V_16;
}
V_11 = F_39 ( V_48 , F_47 ( V_48 ) ) ;
if ( V_11 )
goto V_16;
V_9 = F_9 () ;
V_14 += V_9 - V_8 ;
}
V_16:
if ( V_11 )
return V_11 ;
F_48 ( L_13 ,
V_14 / 8 , V_14 / ( 8 * V_6 ) ) ;
return 0 ;
}
static void F_51 ( const char * V_17 , unsigned int V_7 ,
struct V_41 * V_42 )
{
struct V_4 V_5 [ V_34 ] ;
struct V_50 V_59 ;
struct V_55 * V_48 ;
struct V_60 * V_27 ;
static char V_44 [ 1024 ] ;
int V_15 , V_11 ;
F_5 ( V_45 L_20 , V_17 ) ;
V_27 = F_52 ( V_17 , 0 , 0 ) ;
if ( F_14 ( V_27 ) ) {
F_53 ( L_6 ,
V_17 , F_15 ( V_27 ) ) ;
return;
}
if ( F_54 ( V_27 ) > sizeof( V_44 ) ) {
F_53 ( L_15 ,
F_54 ( V_27 ) , sizeof( V_44 ) ) ;
goto V_16;
}
F_31 ( V_5 ) ;
V_48 = F_55 ( V_27 , V_61 ) ;
if ( ! V_48 ) {
F_53 ( L_21 ) ;
goto V_16;
}
F_56 ( & V_59 . V_54 ) ;
F_57 ( V_48 , V_62 ,
F_37 , & V_59 ) ;
for ( V_15 = 0 ; V_42 [ V_15 ] . V_6 != 0 ; V_15 ++ ) {
if ( V_42 [ V_15 ] . V_6 > V_34 * V_35 ) {
F_53 ( L_16 ,
V_42 [ V_15 ] . V_6 , V_34 * V_35 ) ;
break;
}
F_58 ( L_17
L_18 ,
V_15 , V_42 [ V_15 ] . V_6 , V_42 [ V_15 ] . V_39 , V_42 [ V_15 ] . V_6 / V_42 [ V_15 ] . V_39 ) ;
F_59 ( V_48 , V_5 , V_44 , V_42 [ V_15 ] . V_39 ) ;
if ( V_7 )
V_11 = F_44 ( V_48 , V_42 [ V_15 ] . V_6 ,
V_42 [ V_15 ] . V_39 , V_44 , V_7 ) ;
else
V_11 = F_50 ( V_48 , V_42 [ V_15 ] . V_6 ,
V_42 [ V_15 ] . V_39 , V_44 ) ;
if ( V_11 ) {
F_53 ( L_19 , V_11 ) ;
break;
}
}
F_60 ( V_48 ) ;
V_16:
F_61 ( V_27 ) ;
}
static inline int F_62 ( struct V_63 * V_48 , int V_11 )
{
if ( V_11 == - V_53 || V_11 == - V_56 ) {
struct V_50 * V_57 = V_48 -> V_58 . V_52 ;
V_11 = F_40 ( & V_57 -> V_54 ) ;
if ( ! V_11 )
V_11 = V_57 -> V_49 ;
F_41 ( V_57 -> V_54 ) ;
}
return V_11 ;
}
static int F_63 ( struct V_63 * V_48 , int V_3 ,
int V_6 , int V_7 )
{
unsigned long V_8 , V_9 ;
int V_10 ;
int V_11 ;
for ( V_8 = V_12 , V_9 = V_8 + V_7 * V_13 , V_10 = 0 ;
F_2 ( V_12 , V_9 ) ; V_10 ++ ) {
if ( V_3 )
V_11 = F_62 ( V_48 ,
F_64 ( V_48 ) ) ;
else
V_11 = F_62 ( V_48 ,
F_65 ( V_48 ) ) ;
if ( V_11 )
return V_11 ;
}
F_48 ( L_1 ,
V_10 , V_7 , ( long ) V_10 * V_6 ) ;
return 0 ;
}
static int F_66 ( struct V_63 * V_48 , int V_3 ,
int V_6 )
{
unsigned long V_14 = 0 ;
int V_11 = 0 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
if ( V_3 )
V_11 = F_62 ( V_48 ,
F_64 ( V_48 ) ) ;
else
V_11 = F_62 ( V_48 ,
F_65 ( V_48 ) ) ;
if ( V_11 )
goto V_16;
}
for ( V_15 = 0 ; V_15 < 8 ; V_15 ++ ) {
T_1 V_8 , V_9 ;
V_8 = F_9 () ;
if ( V_3 )
V_11 = F_62 ( V_48 ,
F_64 ( V_48 ) ) ;
else
V_11 = F_62 ( V_48 ,
F_65 ( V_48 ) ) ;
V_9 = F_9 () ;
if ( V_11 )
goto V_16;
V_14 += V_9 - V_8 ;
}
V_16:
if ( V_11 == 0 )
F_48 ( L_2 ,
( V_14 + 4 ) / 8 , V_6 ) ;
return V_11 ;
}
static void F_67 ( const char * V_17 , int V_3 , unsigned int V_7 ,
struct V_18 * V_19 ,
unsigned int V_20 , T_2 * V_21 )
{
unsigned int V_11 , V_15 , V_22 , V_23 ;
struct V_50 V_59 ;
const char * V_24 ;
char V_25 [ 128 ] ;
struct V_63 * V_48 ;
struct V_64 * V_27 ;
const char * V_28 ;
T_3 * V_29 ;
if ( V_3 == V_30 )
V_28 = L_3 ;
else
V_28 = L_4 ;
F_58 ( L_22 , V_17 , V_28 ) ;
F_56 ( & V_59 . V_54 ) ;
V_27 = F_68 ( V_17 , 0 , 0 ) ;
if ( F_14 ( V_27 ) ) {
F_53 ( L_6 , V_17 ,
F_15 ( V_27 ) ) ;
return;
}
V_48 = F_69 ( V_27 , V_61 ) ;
if ( ! V_48 ) {
F_53 ( L_23 ,
V_17 ) ;
goto V_16;
}
F_70 ( V_48 , V_62 ,
F_37 , & V_59 ) ;
V_15 = 0 ;
do {
V_29 = V_33 ;
do {
struct V_4 V_5 [ V_34 ] ;
if ( ( * V_21 + * V_29 ) > V_34 * V_35 ) {
F_53 ( L_7
L_8 , * V_21 + * V_29 ,
V_34 * V_35 ) ;
goto V_65;
}
F_58 ( L_9 , V_15 ,
* V_21 * 8 , * V_29 ) ;
memset ( V_36 [ 0 ] , 0xff , V_35 ) ;
V_24 = V_36 [ 0 ] ;
for ( V_22 = 0 ; V_22 < V_20 ; V_22 ++ ) {
if ( V_19 [ V_22 ] . V_37 == * V_21 ) {
V_24 = V_19 [ V_22 ] . V_24 ;
break;
}
}
F_71 ( V_27 , ~ 0 ) ;
V_11 = F_72 ( V_27 , V_24 , * V_21 ) ;
if ( V_11 ) {
F_53 ( L_10 ,
F_73 ( V_27 ) ) ;
goto V_65;
}
F_18 ( V_5 , V_34 ) ;
F_19 ( V_5 , V_36 [ 0 ] + * V_21 ,
V_35 - * V_21 ) ;
for ( V_22 = 1 ; V_22 < V_34 ; V_22 ++ ) {
F_19 ( V_5 + V_22 , V_36 [ V_22 ] , V_35 ) ;
memset ( V_36 [ V_22 ] , 0xff , V_35 ) ;
}
V_23 = F_74 ( V_27 ) ;
if ( V_23 )
memset ( & V_25 , 0xff , V_23 ) ;
F_75 ( V_48 , V_5 , V_5 , * V_29 , V_25 ) ;
if ( V_7 )
V_11 = F_63 ( V_48 , V_3 ,
* V_29 , V_7 ) ;
else
V_11 = F_66 ( V_48 , V_3 ,
* V_29 ) ;
if ( V_11 ) {
F_53 ( L_11 , V_28 ,
F_73 ( V_27 ) ) ;
break;
}
V_29 ++ ;
V_15 ++ ;
} while ( * V_29 );
V_21 ++ ;
} while ( * V_21 );
V_65:
F_76 ( V_48 ) ;
V_16:
F_77 ( V_27 ) ;
}
static void F_78 ( void )
{
char * * V_66 = V_67 ;
while ( * V_66 ) {
F_5 ( L_24 , * V_66 ) ;
F_5 ( F_79 ( * V_66 , 0 , 0 ) ?
L_25 : L_26 ) ;
V_66 ++ ;
}
}
static inline int F_80 ( const char * V_68 )
{
int V_11 ;
V_11 = F_81 ( V_68 , V_68 , 0 , 0 ) ;
if ( V_69 && V_11 == - V_70 )
V_11 = 0 ;
return V_11 ;
}
static int F_82 ( int V_71 )
{
int V_15 ;
int V_11 = 0 ;
switch ( V_71 ) {
case 0 :
for ( V_15 = 1 ; V_15 < 200 ; V_15 ++ )
V_11 += F_82 ( V_15 ) ;
break;
case 1 :
V_11 += F_80 ( L_27 ) ;
break;
case 2 :
V_11 += F_80 ( L_28 ) ;
break;
case 3 :
V_11 += F_80 ( L_29 ) ;
V_11 += F_80 ( L_30 ) ;
break;
case 4 :
V_11 += F_80 ( L_31 ) ;
V_11 += F_80 ( L_32 ) ;
break;
case 5 :
V_11 += F_80 ( L_33 ) ;
break;
case 6 :
V_11 += F_80 ( L_34 ) ;
break;
case 7 :
V_11 += F_80 ( L_35 ) ;
V_11 += F_80 ( L_36 ) ;
V_11 += F_80 ( L_37 ) ;
break;
case 8 :
V_11 += F_80 ( L_38 ) ;
V_11 += F_80 ( L_39 ) ;
V_11 += F_80 ( L_40 ) ;
V_11 += F_80 ( L_41 ) ;
V_11 += F_80 ( L_42 ) ;
break;
case 9 :
V_11 += F_80 ( L_43 ) ;
V_11 += F_80 ( L_44 ) ;
V_11 += F_80 ( L_45 ) ;
V_11 += F_80 ( L_46 ) ;
V_11 += F_80 ( L_47 ) ;
break;
case 10 :
V_11 += F_80 ( L_48 ) ;
V_11 += F_80 ( L_49 ) ;
V_11 += F_80 ( L_50 ) ;
V_11 += F_80 ( L_51 ) ;
V_11 += F_80 ( L_52 ) ;
V_11 += F_80 ( L_53 ) ;
break;
case 11 :
V_11 += F_80 ( L_54 ) ;
break;
case 12 :
V_11 += F_80 ( L_55 ) ;
break;
case 13 :
V_11 += F_80 ( L_56 ) ;
break;
case 14 :
V_11 += F_80 ( L_57 ) ;
break;
case 15 :
V_11 += F_80 ( L_58 ) ;
break;
case 16 :
V_11 += F_80 ( L_59 ) ;
break;
case 17 :
V_11 += F_80 ( L_60 ) ;
break;
case 18 :
V_11 += F_80 ( L_61 ) ;
break;
case 19 :
V_11 += F_80 ( L_62 ) ;
break;
case 20 :
V_11 += F_80 ( L_63 ) ;
break;
case 21 :
V_11 += F_80 ( L_64 ) ;
break;
case 22 :
V_11 += F_80 ( L_65 ) ;
break;
case 23 :
V_11 += F_80 ( L_66 ) ;
break;
case 24 :
V_11 += F_80 ( L_67 ) ;
break;
case 25 :
V_11 += F_80 ( L_68 ) ;
break;
case 26 :
V_11 += F_80 ( L_69 ) ;
V_11 += F_80 ( L_70 ) ;
break;
case 27 :
V_11 += F_80 ( L_71 ) ;
break;
case 28 :
V_11 += F_80 ( L_72 ) ;
break;
case 29 :
V_11 += F_80 ( L_73 ) ;
break;
case 30 :
V_11 += F_80 ( L_74 ) ;
break;
case 31 :
V_11 += F_80 ( L_75 ) ;
break;
case 32 :
V_11 += F_80 ( L_76 ) ;
V_11 += F_80 ( L_77 ) ;
break;
case 33 :
V_11 += F_80 ( L_78 ) ;
break;
case 34 :
V_11 += F_80 ( L_79 ) ;
break;
case 35 :
V_11 += F_80 ( L_80 ) ;
break;
case 36 :
V_11 += F_80 ( L_81 ) ;
break;
case 37 :
V_11 += F_80 ( L_82 ) ;
break;
case 38 :
V_11 += F_80 ( L_83 ) ;
break;
case 39 :
V_11 += F_80 ( L_84 ) ;
break;
case 40 :
V_11 += F_80 ( L_85 ) ;
break;
case 41 :
V_11 += F_80 ( L_86 ) ;
break;
case 42 :
V_11 += F_80 ( L_87 ) ;
break;
case 43 :
V_11 += F_80 ( L_88 ) ;
break;
case 44 :
V_11 += F_80 ( L_89 ) ;
break;
case 45 :
V_11 += F_80 ( L_90 ) ;
break;
case 100 :
V_11 += F_80 ( L_91 ) ;
break;
case 101 :
V_11 += F_80 ( L_92 ) ;
break;
case 102 :
V_11 += F_80 ( L_93 ) ;
break;
case 103 :
V_11 += F_80 ( L_94 ) ;
break;
case 104 :
V_11 += F_80 ( L_95 ) ;
break;
case 105 :
V_11 += F_80 ( L_96 ) ;
break;
case 106 :
V_11 += F_80 ( L_97 ) ;
break;
case 107 :
V_11 += F_80 ( L_98 ) ;
break;
case 108 :
V_11 += F_80 ( L_99 ) ;
break;
case 109 :
V_11 += F_80 ( L_100 ) ;
break;
case 150 :
V_11 += F_80 ( L_101 ) ;
break;
case 151 :
V_11 += F_80 ( L_102 ) ;
break;
case 200 :
F_12 ( L_48 , V_30 , V_7 , NULL , 0 ,
V_72 ) ;
F_12 ( L_48 , V_73 , V_7 , NULL , 0 ,
V_72 ) ;
F_12 ( L_49 , V_30 , V_7 , NULL , 0 ,
V_72 ) ;
F_12 ( L_49 , V_73 , V_7 , NULL , 0 ,
V_72 ) ;
F_12 ( L_50 , V_30 , V_7 , NULL , 0 ,
V_74 ) ;
F_12 ( L_50 , V_73 , V_7 , NULL , 0 ,
V_74 ) ;
F_12 ( L_51 , V_30 , V_7 , NULL , 0 ,
V_75 ) ;
F_12 ( L_51 , V_73 , V_7 , NULL , 0 ,
V_75 ) ;
F_12 ( L_52 , V_30 , V_7 , NULL , 0 ,
V_72 ) ;
F_12 ( L_52 , V_73 , V_7 , NULL , 0 ,
V_72 ) ;
break;
case 201 :
F_12 ( L_31 , V_30 , V_7 ,
V_76 , V_77 ,
V_78 ) ;
F_12 ( L_31 , V_73 , V_7 ,
V_76 , V_77 ,
V_78 ) ;
F_12 ( L_32 , V_30 , V_7 ,
V_76 , V_77 ,
V_78 ) ;
F_12 ( L_32 , V_73 , V_7 ,
V_76 , V_77 ,
V_78 ) ;
break;
case 202 :
F_12 ( L_38 , V_30 , V_7 , NULL , 0 ,
V_72 ) ;
F_12 ( L_38 , V_73 , V_7 , NULL , 0 ,
V_72 ) ;
F_12 ( L_39 , V_30 , V_7 , NULL , 0 ,
V_72 ) ;
F_12 ( L_39 , V_73 , V_7 , NULL , 0 ,
V_72 ) ;
F_12 ( L_40 , V_30 , V_7 , NULL , 0 ,
V_72 ) ;
F_12 ( L_40 , V_73 , V_7 , NULL , 0 ,
V_72 ) ;
F_12 ( L_41 , V_30 , V_7 , NULL , 0 ,
V_74 ) ;
F_12 ( L_41 , V_73 , V_7 , NULL , 0 ,
V_74 ) ;
F_12 ( L_42 , V_30 , V_7 , NULL , 0 ,
V_75 ) ;
F_12 ( L_42 , V_73 , V_7 , NULL , 0 ,
V_75 ) ;
break;
case 203 :
F_12 ( L_35 , V_30 , V_7 , NULL , 0 ,
V_79 ) ;
F_12 ( L_35 , V_73 , V_7 , NULL , 0 ,
V_79 ) ;
F_12 ( L_36 , V_30 , V_7 , NULL , 0 ,
V_79 ) ;
F_12 ( L_36 , V_73 , V_7 , NULL , 0 ,
V_79 ) ;
F_12 ( L_37 , V_30 , V_7 , NULL , 0 ,
V_79 ) ;
F_12 ( L_37 , V_73 , V_7 , NULL , 0 ,
V_79 ) ;
break;
case 204 :
F_12 ( L_29 , V_30 , V_7 , NULL , 0 ,
V_80 ) ;
F_12 ( L_29 , V_73 , V_7 , NULL , 0 ,
V_80 ) ;
F_12 ( L_30 , V_30 , V_7 , NULL , 0 ,
V_80 ) ;
F_12 ( L_30 , V_73 , V_7 , NULL , 0 ,
V_80 ) ;
break;
case 205 :
F_12 ( L_76 , V_30 , V_7 , NULL , 0 ,
V_72 ) ;
F_12 ( L_76 , V_73 , V_7 , NULL , 0 ,
V_72 ) ;
F_12 ( L_77 , V_30 , V_7 , NULL , 0 ,
V_72 ) ;
F_12 ( L_77 , V_73 , V_7 , NULL , 0 ,
V_72 ) ;
F_12 ( L_103 , V_30 , V_7 , NULL , 0 ,
V_72 ) ;
F_12 ( L_103 , V_73 , V_7 , NULL , 0 ,
V_72 ) ;
F_12 ( L_104 , V_30 , V_7 , NULL , 0 ,
V_74 ) ;
F_12 ( L_104 , V_73 , V_7 , NULL , 0 ,
V_74 ) ;
F_12 ( L_105 , V_30 , V_7 , NULL , 0 ,
V_75 ) ;
F_12 ( L_105 , V_73 , V_7 , NULL , 0 ,
V_75 ) ;
break;
case 206 :
F_12 ( L_79 , V_30 , V_7 , NULL , 0 ,
V_81 ) ;
break;
case 207 :
F_12 ( L_43 , V_30 , V_7 , NULL , 0 ,
V_81 ) ;
F_12 ( L_43 , V_73 , V_7 , NULL , 0 ,
V_81 ) ;
F_12 ( L_44 , V_30 , V_7 , NULL , 0 ,
V_81 ) ;
F_12 ( L_44 , V_73 , V_7 , NULL , 0 ,
V_81 ) ;
F_12 ( L_45 , V_30 , V_7 , NULL , 0 ,
V_81 ) ;
F_12 ( L_45 , V_73 , V_7 , NULL , 0 ,
V_81 ) ;
F_12 ( L_46 , V_30 , V_7 , NULL , 0 ,
V_82 ) ;
F_12 ( L_46 , V_73 , V_7 , NULL , 0 ,
V_82 ) ;
F_12 ( L_47 , V_30 , V_7 , NULL , 0 ,
V_83 ) ;
F_12 ( L_47 , V_73 , V_7 , NULL , 0 ,
V_83 ) ;
break;
case 300 :
case 301 :
F_32 ( L_33 , V_7 , V_84 ) ;
if ( V_85 > 300 && V_85 < 400 ) break;
case 302 :
F_32 ( L_27 , V_7 , V_84 ) ;
if ( V_85 > 300 && V_85 < 400 ) break;
case 303 :
F_32 ( L_28 , V_7 , V_84 ) ;
if ( V_85 > 300 && V_85 < 400 ) break;
case 304 :
F_32 ( L_34 , V_7 , V_84 ) ;
if ( V_85 > 300 && V_85 < 400 ) break;
case 305 :
F_32 ( L_54 , V_7 , V_84 ) ;
if ( V_85 > 300 && V_85 < 400 ) break;
case 306 :
F_32 ( L_55 , V_7 , V_84 ) ;
if ( V_85 > 300 && V_85 < 400 ) break;
case 307 :
F_32 ( L_67 , V_7 , V_84 ) ;
if ( V_85 > 300 && V_85 < 400 ) break;
case 308 :
F_32 ( L_66 , V_7 , V_84 ) ;
if ( V_85 > 300 && V_85 < 400 ) break;
case 309 :
F_32 ( L_65 , V_7 , V_84 ) ;
if ( V_85 > 300 && V_85 < 400 ) break;
case 310 :
F_32 ( L_73 , V_7 , V_84 ) ;
if ( V_85 > 300 && V_85 < 400 ) break;
case 311 :
F_32 ( L_72 , V_7 , V_84 ) ;
if ( V_85 > 300 && V_85 < 400 ) break;
case 312 :
F_32 ( L_71 , V_7 , V_84 ) ;
if ( V_85 > 300 && V_85 < 400 ) break;
case 313 :
F_32 ( L_78 , V_7 , V_84 ) ;
if ( V_85 > 300 && V_85 < 400 ) break;
case 314 :
F_32 ( L_84 , V_7 , V_84 ) ;
if ( V_85 > 300 && V_85 < 400 ) break;
case 315 :
F_32 ( L_85 , V_7 , V_84 ) ;
if ( V_85 > 300 && V_85 < 400 ) break;
case 316 :
F_32 ( L_86 , V_7 , V_84 ) ;
if ( V_85 > 300 && V_85 < 400 ) break;
case 317 :
F_32 ( L_87 , V_7 , V_84 ) ;
if ( V_85 > 300 && V_85 < 400 ) break;
case 318 :
F_32 ( L_106 , V_7 , V_86 ) ;
if ( V_85 > 300 && V_85 < 400 ) break;
case 399 :
break;
case 400 :
case 401 :
F_51 ( L_33 , V_7 , V_84 ) ;
if ( V_85 > 400 && V_85 < 500 ) break;
case 402 :
F_51 ( L_27 , V_7 , V_84 ) ;
if ( V_85 > 400 && V_85 < 500 ) break;
case 403 :
F_51 ( L_28 , V_7 , V_84 ) ;
if ( V_85 > 400 && V_85 < 500 ) break;
case 404 :
F_51 ( L_34 , V_7 , V_84 ) ;
if ( V_85 > 400 && V_85 < 500 ) break;
case 405 :
F_51 ( L_54 , V_7 , V_84 ) ;
if ( V_85 > 400 && V_85 < 500 ) break;
case 406 :
F_51 ( L_55 , V_7 , V_84 ) ;
if ( V_85 > 400 && V_85 < 500 ) break;
case 407 :
F_51 ( L_67 , V_7 , V_84 ) ;
if ( V_85 > 400 && V_85 < 500 ) break;
case 408 :
F_51 ( L_66 , V_7 , V_84 ) ;
if ( V_85 > 400 && V_85 < 500 ) break;
case 409 :
F_51 ( L_65 , V_7 , V_84 ) ;
if ( V_85 > 400 && V_85 < 500 ) break;
case 410 :
F_51 ( L_73 , V_7 , V_84 ) ;
if ( V_85 > 400 && V_85 < 500 ) break;
case 411 :
F_51 ( L_72 , V_7 , V_84 ) ;
if ( V_85 > 400 && V_85 < 500 ) break;
case 412 :
F_51 ( L_71 , V_7 , V_84 ) ;
if ( V_85 > 400 && V_85 < 500 ) break;
case 413 :
F_51 ( L_78 , V_7 , V_84 ) ;
if ( V_85 > 400 && V_85 < 500 ) break;
case 414 :
F_51 ( L_84 , V_7 , V_84 ) ;
if ( V_85 > 400 && V_85 < 500 ) break;
case 415 :
F_51 ( L_85 , V_7 , V_84 ) ;
if ( V_85 > 400 && V_85 < 500 ) break;
case 416 :
F_51 ( L_86 , V_7 , V_84 ) ;
if ( V_85 > 400 && V_85 < 500 ) break;
case 417 :
F_51 ( L_87 , V_7 , V_84 ) ;
if ( V_85 > 400 && V_85 < 500 ) break;
case 499 :
break;
case 500 :
F_67 ( L_48 , V_30 , V_7 , NULL , 0 ,
V_72 ) ;
F_67 ( L_48 , V_73 , V_7 , NULL , 0 ,
V_72 ) ;
F_67 ( L_49 , V_30 , V_7 , NULL , 0 ,
V_72 ) ;
F_67 ( L_49 , V_73 , V_7 , NULL , 0 ,
V_72 ) ;
F_67 ( L_50 , V_30 , V_7 , NULL , 0 ,
V_74 ) ;
F_67 ( L_50 , V_73 , V_7 , NULL , 0 ,
V_74 ) ;
F_67 ( L_51 , V_30 , V_7 , NULL , 0 ,
V_75 ) ;
F_67 ( L_51 , V_73 , V_7 , NULL , 0 ,
V_75 ) ;
F_67 ( L_52 , V_30 , V_7 , NULL , 0 ,
V_72 ) ;
F_67 ( L_52 , V_73 , V_7 , NULL , 0 ,
V_72 ) ;
break;
case 501 :
F_67 ( L_31 , V_30 , V_7 ,
V_76 , V_77 ,
V_78 ) ;
F_67 ( L_31 , V_73 , V_7 ,
V_76 , V_77 ,
V_78 ) ;
F_67 ( L_32 , V_30 , V_7 ,
V_76 , V_77 ,
V_78 ) ;
F_67 ( L_32 , V_73 , V_7 ,
V_76 , V_77 ,
V_78 ) ;
break;
case 502 :
F_67 ( L_29 , V_30 , V_7 , NULL , 0 ,
V_80 ) ;
F_67 ( L_29 , V_73 , V_7 , NULL , 0 ,
V_80 ) ;
F_67 ( L_30 , V_30 , V_7 , NULL , 0 ,
V_80 ) ;
F_67 ( L_30 , V_73 , V_7 , NULL , 0 ,
V_80 ) ;
break;
case 503 :
F_67 ( L_43 , V_30 , V_7 , NULL , 0 ,
V_81 ) ;
F_67 ( L_43 , V_73 , V_7 , NULL , 0 ,
V_81 ) ;
F_67 ( L_44 , V_30 , V_7 , NULL , 0 ,
V_81 ) ;
F_67 ( L_44 , V_73 , V_7 , NULL , 0 ,
V_81 ) ;
F_67 ( L_45 , V_30 , V_7 , NULL , 0 ,
V_81 ) ;
F_67 ( L_45 , V_73 , V_7 , NULL , 0 ,
V_81 ) ;
F_67 ( L_46 , V_30 , V_7 , NULL , 0 ,
V_82 ) ;
F_67 ( L_46 , V_73 , V_7 , NULL , 0 ,
V_82 ) ;
F_67 ( L_47 , V_30 , V_7 , NULL , 0 ,
V_83 ) ;
F_67 ( L_47 , V_73 , V_7 , NULL , 0 ,
V_83 ) ;
break;
case 1000 :
F_78 () ;
break;
}
return V_11 ;
}
static int F_83 ( const char * V_68 , T_3 type , T_3 V_87 )
{
return F_79 ( V_68 , type , V_87 ? : V_88 ) ?
0 : - V_89 ;
}
static int T_4 F_84 ( void )
{
int V_49 = - V_90 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_34 ; V_15 ++ ) {
V_36 [ V_15 ] = ( void * ) F_85 ( V_61 ) ;
if ( ! V_36 [ V_15 ] )
goto V_91;
}
if ( V_68 )
V_49 = F_83 ( V_68 , type , V_87 ) ;
else
V_49 = F_82 ( V_85 ) ;
if ( V_49 ) {
F_5 ( V_46 L_107 ) ;
goto V_91;
}
if ( ! V_69 )
V_49 = - V_92 ;
V_91:
for ( V_15 = 0 ; V_15 < V_34 && V_36 [ V_15 ] ; V_15 ++ )
F_86 ( ( unsigned long ) V_36 [ V_15 ] ) ;
return V_49 ;
}
static void T_5 F_87 ( void ) { }
