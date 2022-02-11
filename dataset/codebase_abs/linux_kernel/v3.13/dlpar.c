void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_2 ( V_2 -> V_4 ) ;
F_2 ( V_2 ) ;
}
static struct V_1 * F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
char * V_3 ;
char * V_4 ;
V_2 = F_4 ( sizeof( * V_2 ) , V_7 ) ;
if ( ! V_2 )
return NULL ;
V_3 = ( char * ) V_6 + V_6 -> V_8 ;
V_2 -> V_3 = F_5 ( V_3 , V_7 ) ;
V_2 -> V_9 = V_6 -> V_10 ;
V_4 = ( char * ) V_6 + V_6 -> V_11 ;
V_2 -> V_4 = F_6 ( V_4 , V_2 -> V_9 , V_7 ) ;
if ( ! V_2 -> V_4 ) {
F_1 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static struct V_12 * F_7 ( struct V_5 * V_6 ,
const char * V_13 )
{
struct V_12 * V_14 ;
char * V_3 ;
if ( ! V_13 [ 1 ] )
V_13 ++ ;
V_14 = F_4 ( sizeof( * V_14 ) , V_7 ) ;
if ( ! V_14 )
return NULL ;
V_3 = ( char * ) V_6 + V_6 -> V_8 ;
V_14 -> V_15 = F_8 ( V_7 , L_1 , V_13 , V_3 ) ;
if ( ! V_14 -> V_15 ) {
F_2 ( V_14 ) ;
return NULL ;
}
F_9 ( V_14 , V_16 ) ;
F_10 ( & V_14 -> V_17 ) ;
return V_14 ;
}
static void F_11 ( struct V_12 * V_14 )
{
struct V_1 * V_2 ;
while ( V_14 -> V_18 ) {
V_2 = V_14 -> V_18 ;
V_14 -> V_18 = V_2 -> V_19 ;
F_1 ( V_2 ) ;
}
F_2 ( V_14 -> V_15 ) ;
F_2 ( V_14 ) ;
}
void F_12 ( struct V_12 * V_14 )
{
if ( V_14 -> V_20 )
F_12 ( V_14 -> V_20 ) ;
if ( V_14 -> V_21 )
F_12 ( V_14 -> V_21 ) ;
F_11 ( V_14 ) ;
}
struct V_12 * F_13 ( T_1 V_22 ,
struct V_12 * V_23 )
{
struct V_12 * V_14 ;
struct V_12 * V_24 = NULL ;
struct V_12 * V_25 = NULL ;
struct V_1 * V_1 ;
struct V_1 * V_26 = NULL ;
struct V_5 * V_6 ;
char * V_27 ;
const char * V_28 = V_23 -> V_15 ;
int V_29 ;
int V_30 = - 1 ;
V_29 = F_14 ( L_2 ) ;
if ( V_29 == V_31 )
return NULL ;
V_27 = F_4 ( V_32 , V_7 ) ;
if ( ! V_27 )
return NULL ;
V_6 = (struct V_5 * ) & V_27 [ 0 ] ;
V_6 -> V_22 = V_22 ;
V_6 -> V_33 = 0 ;
do {
F_15 ( & V_34 ) ;
memcpy ( V_35 , V_27 , V_32 ) ;
V_30 = F_16 ( V_29 , 2 , 1 , NULL , V_35 , NULL ) ;
memcpy ( V_27 , V_35 , V_32 ) ;
F_17 ( & V_34 ) ;
switch ( V_30 ) {
case V_36 :
break;
case V_37 :
V_14 = F_7 ( V_6 , V_28 ) ;
if ( ! V_14 )
goto V_38;
V_14 -> V_23 = V_25 -> V_23 ;
V_25 -> V_21 = V_14 ;
V_25 = V_14 ;
break;
case V_39 :
if ( V_24 )
V_28 = V_25 -> V_15 ;
V_14 = F_7 ( V_6 , V_28 ) ;
if ( ! V_14 )
goto V_38;
if ( ! V_24 ) {
V_14 -> V_23 = V_23 ;
V_24 = V_14 ;
} else {
V_14 -> V_23 = V_25 ;
if ( V_25 )
V_25 -> V_20 = V_14 ;
}
V_25 = V_14 ;
break;
case V_40 :
V_1 = F_3 ( V_6 ) ;
if ( ! V_1 )
goto V_38;
if ( ! V_25 -> V_18 )
V_25 -> V_18 = V_1 ;
else
V_26 -> V_19 = V_1 ;
V_26 = V_1 ;
break;
case V_41 :
V_25 = V_25 -> V_23 ;
V_28 = V_25 -> V_23 -> V_15 ;
break;
case V_42 :
break;
case V_43 :
case V_44 :
default:
F_18 ( V_45 L_3
L_4 , V_30 ) ;
goto V_38;
}
} while ( V_30 );
V_38:
F_2 ( V_27 ) ;
if ( V_30 ) {
if ( V_24 )
F_12 ( V_24 ) ;
return NULL ;
}
return V_24 ;
}
static struct V_12 * F_19 ( const char * V_13 )
{
struct V_12 * V_23 ;
char * V_46 ;
V_46 = strrchr ( V_13 , '/' ) ;
if ( V_46 == V_13 ) {
V_23 = F_20 ( L_5 ) ;
} else {
char * V_28 ;
int V_47 = V_46 - V_13 + 1 ;
V_28 = F_21 ( V_47 , V_7 ) ;
if ( ! V_28 )
return NULL ;
F_22 ( V_28 , V_13 , V_47 ) ;
V_23 = F_20 ( V_28 ) ;
F_2 ( V_28 ) ;
}
return V_23 ;
}
int F_23 ( struct V_12 * V_14 )
{
int V_30 ;
V_14 -> V_23 = F_19 ( V_14 -> V_15 ) ;
if ( ! V_14 -> V_23 )
return - V_48 ;
V_30 = F_24 ( V_14 ) ;
if ( V_30 ) {
F_18 ( V_45 L_6 ,
V_14 -> V_15 ) ;
return V_30 ;
}
F_25 ( V_14 -> V_23 ) ;
return 0 ;
}
int F_26 ( struct V_12 * V_14 )
{
struct V_12 * V_20 ;
int V_30 ;
V_20 = F_27 ( V_14 , NULL ) ;
while ( V_20 ) {
F_26 ( V_20 ) ;
V_20 = F_27 ( V_14 , V_20 ) ;
}
V_30 = F_28 ( V_14 ) ;
if ( V_30 )
return V_30 ;
F_25 ( V_14 ) ;
return 0 ;
}
int F_29 ( T_1 V_22 )
{
int V_49 , V_30 ;
V_30 = F_16 ( F_14 ( L_7 ) , 2 , 2 , & V_49 ,
V_50 , V_22 ) ;
if ( V_30 || V_49 != V_51 )
return - 1 ;
V_30 = F_30 ( V_52 , V_22 , V_53 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_30 ( V_54 , V_22 , V_55 ) ;
if ( V_30 ) {
F_30 ( V_52 , V_22 , V_56 ) ;
return V_30 ;
}
return 0 ;
}
int F_31 ( T_1 V_22 )
{
int V_49 , V_30 ;
V_30 = F_16 ( F_14 ( L_7 ) , 2 , 2 , & V_49 ,
V_50 , V_22 ) ;
if ( V_30 || V_49 != V_57 )
return - 1 ;
V_30 = F_30 ( V_54 , V_22 , V_58 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_30 ( V_52 , V_22 , V_56 ) ;
if ( V_30 ) {
F_30 ( V_54 , V_22 , V_55 ) ;
return V_30 ;
}
return 0 ;
}
static int F_32 ( struct V_12 * V_14 )
{
int V_30 = 0 ;
unsigned int V_59 ;
int V_60 , V_61 , V_62 ;
const T_1 * V_63 ;
V_63 = F_33 ( V_14 , L_8 , & V_60 ) ;
if ( ! V_63 )
return - V_64 ;
V_61 = V_60 / sizeof( T_1 ) ;
F_34 () ;
for ( V_62 = 0 ; V_62 < V_61 ; V_62 ++ ) {
F_35 (cpu) {
if ( F_36 ( V_59 ) != V_63 [ V_62 ] )
continue;
F_37 ( F_38 ( V_59 )
!= V_65 ) ;
F_39 () ;
V_30 = F_40 ( V_59 ) ;
if ( V_30 )
goto V_66;
F_34 () ;
break;
}
if ( V_59 == F_41 () )
F_18 ( V_67 L_9
L_10 , V_63 [ V_62 ] ) ;
}
F_39 () ;
V_66:
return V_30 ;
}
static T_2 F_42 ( const char * V_68 , T_3 V_69 )
{
struct V_12 * V_14 , * V_23 ;
unsigned long V_22 ;
int V_30 ;
V_30 = F_43 ( V_68 , 0 , & V_22 ) ;
if ( V_30 )
return - V_64 ;
V_23 = F_20 ( L_11 ) ;
if ( ! V_23 )
return - V_70 ;
V_14 = F_13 ( V_22 , V_23 ) ;
if ( ! V_14 )
return - V_64 ;
F_25 ( V_23 ) ;
V_30 = F_29 ( V_22 ) ;
if ( V_30 ) {
F_12 ( V_14 ) ;
return - V_64 ;
}
V_30 = F_23 ( V_14 ) ;
if ( V_30 ) {
F_31 ( V_22 ) ;
F_12 ( V_14 ) ;
return V_30 ;
}
V_30 = F_32 ( V_14 ) ;
if ( V_30 )
return V_30 ;
return V_69 ;
}
static int F_44 ( struct V_12 * V_14 )
{
int V_30 = 0 ;
unsigned int V_59 ;
int V_60 , V_61 , V_62 ;
const T_1 * V_63 ;
V_63 = F_33 ( V_14 , L_8 , & V_60 ) ;
if ( ! V_63 )
return - V_64 ;
V_61 = V_60 / sizeof( T_1 ) ;
F_34 () ;
for ( V_62 = 0 ; V_62 < V_61 ; V_62 ++ ) {
F_35 (cpu) {
if ( F_36 ( V_59 ) != V_63 [ V_62 ] )
continue;
if ( F_38 ( V_59 ) == V_65 )
break;
if ( F_38 ( V_59 ) == V_71 ) {
F_45 ( V_59 , V_65 ) ;
F_39 () ;
V_30 = F_46 ( V_59 ) ;
if ( V_30 )
goto V_66;
F_34 () ;
break;
}
F_45 ( V_59 , V_65 ) ;
F_37 ( F_47 ( V_72 , V_63 [ V_62 ] )
!= V_73 ) ;
F_48 ( V_59 ) ;
break;
}
if ( V_59 == F_41 () )
F_18 ( V_67 L_12
L_10 , V_63 [ V_62 ] ) ;
}
F_39 () ;
V_66:
return V_30 ;
}
static T_2 F_49 ( const char * V_68 , T_3 V_69 )
{
struct V_12 * V_14 ;
const T_1 * V_22 ;
int V_30 ;
V_14 = F_20 ( V_68 ) ;
if ( ! V_14 )
return - V_64 ;
V_22 = F_33 ( V_14 , L_13 , NULL ) ;
if ( ! V_22 ) {
F_25 ( V_14 ) ;
return - V_64 ;
}
V_30 = F_44 ( V_14 ) ;
if ( V_30 ) {
F_25 ( V_14 ) ;
return - V_64 ;
}
V_30 = F_31 ( * V_22 ) ;
if ( V_30 ) {
F_25 ( V_14 ) ;
return V_30 ;
}
V_30 = F_26 ( V_14 ) ;
if ( V_30 ) {
F_29 ( * V_22 ) ;
return V_30 ;
}
F_25 ( V_14 ) ;
return V_69 ;
}
static int T_4 F_50 ( void )
{
V_74 . V_75 = F_42 ;
V_74 . V_76 = F_49 ;
return 0 ;
}
