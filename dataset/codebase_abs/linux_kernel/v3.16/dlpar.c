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
F_10 ( V_14 ) ;
return V_14 ;
}
static void F_11 ( struct V_12 * V_14 )
{
struct V_1 * V_2 ;
while ( V_14 -> V_17 ) {
V_2 = V_14 -> V_17 ;
V_14 -> V_17 = V_2 -> V_18 ;
F_1 ( V_2 ) ;
}
F_2 ( V_14 -> V_15 ) ;
F_2 ( V_14 ) ;
}
void F_12 ( struct V_12 * V_14 )
{
if ( V_14 -> V_19 )
F_12 ( V_14 -> V_19 ) ;
if ( V_14 -> V_20 )
F_12 ( V_14 -> V_20 ) ;
F_11 ( V_14 ) ;
}
struct V_12 * F_13 ( T_1 V_21 ,
struct V_12 * V_22 )
{
struct V_12 * V_14 ;
struct V_12 * V_23 = NULL ;
struct V_12 * V_24 = NULL ;
struct V_1 * V_1 ;
struct V_1 * V_25 = NULL ;
struct V_5 * V_6 ;
char * V_26 ;
const char * V_27 = V_22 -> V_15 ;
int V_28 ;
int V_29 = - 1 ;
V_28 = F_14 ( L_2 ) ;
if ( V_28 == V_30 )
return NULL ;
V_26 = F_4 ( V_31 , V_7 ) ;
if ( ! V_26 )
return NULL ;
V_6 = (struct V_5 * ) & V_26 [ 0 ] ;
V_6 -> V_21 = V_21 ;
V_6 -> V_32 = 0 ;
do {
F_15 ( & V_33 ) ;
memcpy ( V_34 , V_26 , V_31 ) ;
V_29 = F_16 ( V_28 , 2 , 1 , NULL , V_34 , NULL ) ;
memcpy ( V_26 , V_34 , V_31 ) ;
F_17 ( & V_33 ) ;
switch ( V_29 ) {
case V_35 :
break;
case V_36 :
V_14 = F_7 ( V_6 , V_27 ) ;
if ( ! V_14 )
goto V_37;
V_14 -> V_22 = V_24 -> V_22 ;
V_24 -> V_20 = V_14 ;
V_24 = V_14 ;
break;
case V_38 :
if ( V_23 )
V_27 = V_24 -> V_15 ;
V_14 = F_7 ( V_6 , V_27 ) ;
if ( ! V_14 )
goto V_37;
if ( ! V_23 ) {
V_14 -> V_22 = V_22 ;
V_23 = V_14 ;
} else {
V_14 -> V_22 = V_24 ;
if ( V_24 )
V_24 -> V_19 = V_14 ;
}
V_24 = V_14 ;
break;
case V_39 :
V_1 = F_3 ( V_6 ) ;
if ( ! V_1 )
goto V_37;
if ( ! V_24 -> V_17 )
V_24 -> V_17 = V_1 ;
else
V_25 -> V_18 = V_1 ;
V_25 = V_1 ;
break;
case V_40 :
V_24 = V_24 -> V_22 ;
V_27 = V_24 -> V_22 -> V_15 ;
break;
case V_41 :
break;
case V_42 :
case V_43 :
default:
F_18 ( V_44 L_3
L_4 , V_29 ) ;
goto V_37;
}
} while ( V_29 );
V_37:
F_2 ( V_26 ) ;
if ( V_29 ) {
if ( V_23 )
F_12 ( V_23 ) ;
return NULL ;
}
return V_23 ;
}
static struct V_12 * F_19 ( const char * V_13 )
{
struct V_12 * V_22 ;
char * V_45 ;
V_45 = strrchr ( V_13 , '/' ) ;
if ( V_45 == V_13 ) {
V_22 = F_20 ( L_5 ) ;
} else {
char * V_27 ;
int V_46 = V_45 - V_13 + 1 ;
V_27 = F_21 ( V_46 , V_7 ) ;
if ( ! V_27 )
return NULL ;
F_22 ( V_27 , V_13 , V_46 ) ;
V_22 = F_20 ( V_27 ) ;
F_2 ( V_27 ) ;
}
return V_22 ;
}
int F_23 ( struct V_12 * V_14 )
{
int V_29 ;
V_14 -> V_22 = F_19 ( V_14 -> V_15 ) ;
if ( ! V_14 -> V_22 )
return - V_47 ;
V_29 = F_24 ( V_14 ) ;
if ( V_29 ) {
F_18 ( V_44 L_6 ,
V_14 -> V_15 ) ;
return V_29 ;
}
F_25 ( V_14 -> V_22 ) ;
return 0 ;
}
int F_26 ( struct V_12 * V_14 )
{
struct V_12 * V_19 ;
int V_29 ;
V_19 = F_27 ( V_14 , NULL ) ;
while ( V_19 ) {
F_26 ( V_19 ) ;
V_19 = F_27 ( V_14 , V_19 ) ;
}
V_29 = F_28 ( V_14 ) ;
if ( V_29 )
return V_29 ;
F_25 ( V_14 ) ;
return 0 ;
}
int F_29 ( T_1 V_21 )
{
int V_48 , V_29 ;
V_29 = F_16 ( F_14 ( L_7 ) , 2 , 2 , & V_48 ,
V_49 , V_21 ) ;
if ( V_29 || V_48 != V_50 )
return - 1 ;
V_29 = F_30 ( V_51 , V_21 , V_52 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_30 ( V_53 , V_21 , V_54 ) ;
if ( V_29 ) {
F_30 ( V_51 , V_21 , V_55 ) ;
return V_29 ;
}
return 0 ;
}
int F_31 ( T_1 V_21 )
{
int V_48 , V_29 ;
V_29 = F_16 ( F_14 ( L_7 ) , 2 , 2 , & V_48 ,
V_49 , V_21 ) ;
if ( V_29 || V_48 != V_56 )
return - 1 ;
V_29 = F_30 ( V_53 , V_21 , V_57 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_30 ( V_51 , V_21 , V_55 ) ;
if ( V_29 ) {
F_30 ( V_53 , V_21 , V_54 ) ;
return V_29 ;
}
return 0 ;
}
static int F_32 ( struct V_12 * V_14 )
{
int V_29 = 0 ;
unsigned int V_58 ;
int V_59 , V_60 , V_61 ;
const T_1 * V_62 ;
V_62 = F_33 ( V_14 , L_8 , & V_59 ) ;
if ( ! V_62 )
return - V_63 ;
V_60 = V_59 / sizeof( T_1 ) ;
F_34 () ;
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ ) {
F_35 (cpu) {
if ( F_36 ( V_58 ) != V_62 [ V_61 ] )
continue;
F_37 ( F_38 ( V_58 )
!= V_64 ) ;
F_39 () ;
V_29 = F_40 ( V_58 ) ;
if ( V_29 )
goto V_65;
F_34 () ;
break;
}
if ( V_58 == F_41 () )
F_18 ( V_66 L_9
L_10 , V_62 [ V_61 ] ) ;
}
F_39 () ;
V_65:
return V_29 ;
}
static T_2 F_42 ( const char * V_67 , T_3 V_68 )
{
struct V_12 * V_14 , * V_22 ;
unsigned long V_21 ;
int V_29 ;
V_29 = F_43 ( V_67 , 0 , & V_21 ) ;
if ( V_29 )
return - V_63 ;
V_22 = F_20 ( L_11 ) ;
if ( ! V_22 )
return - V_69 ;
V_14 = F_13 ( V_21 , V_22 ) ;
if ( ! V_14 )
return - V_63 ;
F_25 ( V_22 ) ;
V_29 = F_29 ( V_21 ) ;
if ( V_29 ) {
F_12 ( V_14 ) ;
return - V_63 ;
}
V_29 = F_23 ( V_14 ) ;
if ( V_29 ) {
F_31 ( V_21 ) ;
F_12 ( V_14 ) ;
return V_29 ;
}
V_29 = F_32 ( V_14 ) ;
if ( V_29 )
return V_29 ;
return V_68 ;
}
static int F_44 ( struct V_12 * V_14 )
{
int V_29 = 0 ;
unsigned int V_58 ;
int V_59 , V_60 , V_61 ;
const T_1 * V_62 ;
V_62 = F_33 ( V_14 , L_8 , & V_59 ) ;
if ( ! V_62 )
return - V_63 ;
V_60 = V_59 / sizeof( T_1 ) ;
F_34 () ;
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ ) {
F_35 (cpu) {
if ( F_36 ( V_58 ) != V_62 [ V_61 ] )
continue;
if ( F_38 ( V_58 ) == V_64 )
break;
if ( F_38 ( V_58 ) == V_70 ) {
F_45 ( V_58 , V_64 ) ;
F_39 () ;
V_29 = F_46 ( V_58 ) ;
if ( V_29 )
goto V_65;
F_34 () ;
break;
}
F_45 ( V_58 , V_64 ) ;
F_37 ( F_47 ( V_71 , V_62 [ V_61 ] )
!= V_72 ) ;
F_48 ( V_58 ) ;
break;
}
if ( V_58 == F_41 () )
F_18 ( V_66 L_12
L_10 , V_62 [ V_61 ] ) ;
}
F_39 () ;
V_65:
return V_29 ;
}
static T_2 F_49 ( const char * V_67 , T_3 V_68 )
{
struct V_12 * V_14 ;
const T_1 * V_21 ;
int V_29 ;
V_14 = F_20 ( V_67 ) ;
if ( ! V_14 )
return - V_63 ;
V_21 = F_33 ( V_14 , L_13 , NULL ) ;
if ( ! V_21 ) {
F_25 ( V_14 ) ;
return - V_63 ;
}
V_29 = F_44 ( V_14 ) ;
if ( V_29 ) {
F_25 ( V_14 ) ;
return - V_63 ;
}
V_29 = F_31 ( * V_21 ) ;
if ( V_29 ) {
F_25 ( V_14 ) ;
return V_29 ;
}
V_29 = F_26 ( V_14 ) ;
if ( V_29 ) {
F_29 ( * V_21 ) ;
return V_29 ;
}
F_25 ( V_14 ) ;
return V_68 ;
}
static int T_4 F_50 ( void )
{
V_73 . V_74 = F_42 ;
V_73 . V_75 = F_49 ;
return 0 ;
}
