static void F_1 ( char * * V_1 , int V_2 , int V_3 , struct V_4 * V_5 )
{
if ( V_2 == V_6 )
* V_1 += sprintf ( * V_1 , L_1 ,
V_3 , V_5 -> V_7 . V_8 ) ;
else
* V_1 += sprintf ( * V_1 , L_2 ,
V_3 , V_5 -> V_7 . V_8 ) ;
if ( V_5 -> V_7 . V_8 == V_9 ) {
* V_1 += sprintf ( * V_1 , L_3 ,
V_5 -> V_10 , V_5 -> V_11 ) ;
* V_1 += sprintf ( * V_1 , L_4 ,
V_5 -> V_7 . V_12 ,
F_2 ( & V_5 -> V_13 -> V_14 ) ) ;
} else {
* V_1 += sprintf ( * V_1 , L_5 ) ;
* V_1 += sprintf ( * V_1 , L_6 ) ;
}
* V_1 += sprintf ( * V_1 , L_7 ) ;
}
static T_1 F_3 ( int V_15 , char * V_1 )
{
struct V_16 * V_17 = V_18 [ V_15 ] . V_17 ;
struct V_19 * V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_22 ;
char * V_23 = V_1 ;
int V_24 ;
unsigned long V_25 ;
if ( ! V_17 || ! V_1 ) {
F_4 ( L_8 ) ;
return 0 ;
}
V_21 = F_5 ( V_17 ) ;
V_22 = F_6 ( V_21 ) ;
V_19 = V_22 -> V_19 ;
F_7 ( & V_19 -> V_26 , V_25 ) ;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
struct V_4 * V_5 = & V_19 -> V_28 -> V_5 [ V_24 ] ;
F_8 ( & V_5 -> V_7 . V_26 ) ;
F_1 ( & V_1 , V_6 ,
V_15 * V_29 + V_24 , V_5 ) ;
F_9 ( & V_5 -> V_7 . V_26 ) ;
}
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
struct V_4 * V_5 = & V_19 -> V_30 -> V_5 [ V_24 ] ;
F_8 ( & V_5 -> V_7 . V_26 ) ;
F_1 ( & V_1 , V_31 ,
V_15 * V_29 + V_27 + V_24 , V_5 ) ;
F_9 ( & V_5 -> V_7 . V_26 ) ;
}
F_10 ( & V_19 -> V_26 , V_25 ) ;
return V_1 - V_23 ;
}
static T_1 F_11 ( int V_15 , char * V_1 )
{
char * V_23 = V_1 ;
int V_24 = 0 ;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
V_1 += sprintf ( V_1 , L_1 ,
( V_15 * V_29 ) + V_24 ,
V_32 ) ;
V_1 += sprintf ( V_1 , L_9 ) ;
V_1 += sprintf ( V_1 , L_7 ) ;
}
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
V_1 += sprintf ( V_1 , L_2 ,
( V_15 * V_29 ) + V_27 + V_24 ,
V_32 ) ;
V_1 += sprintf ( V_1 , L_9 ) ;
V_1 += sprintf ( V_1 , L_7 ) ;
}
return V_1 - V_23 ;
}
static int F_12 ( const char * V_33 )
{
char * V_34 ;
long V_35 ;
int V_36 ;
V_34 = strchr ( V_33 , '.' ) ;
if ( V_34 == NULL )
return 0 ;
V_36 = F_13 ( V_34 + 1 , 10 , & V_35 ) ;
if ( V_36 < 0 )
return V_36 ;
return V_35 ;
}
static T_1 F_14 ( struct V_37 * V_14 ,
struct V_38 * V_39 , char * V_1 )
{
char * V_23 = V_1 ;
int V_15 ;
V_1 += sprintf ( V_1 ,
L_10 ) ;
V_15 = F_12 ( V_39 -> V_39 . V_33 ) ;
if ( V_15 < 0 )
V_1 += F_11 ( V_15 , V_1 ) ;
else
V_1 += F_3 ( V_15 , V_1 ) ;
return V_1 - V_23 ;
}
static T_1 F_15 ( struct V_37 * V_14 , struct V_38 * V_39 ,
char * V_1 )
{
char * V_23 = V_1 ;
V_1 += sprintf ( V_1 , L_11 , V_29 * V_40 ) ;
return V_1 - V_23 ;
}
static int F_16 ( struct V_22 * V_22 , T_2 V_41 )
{
struct V_4 * V_5 = & V_22 -> V_5 [ V_41 ] ;
struct V_19 * V_19 = V_22 -> V_19 ;
unsigned long V_25 ;
F_4 ( L_12 ) ;
F_7 ( & V_19 -> V_26 , V_25 ) ;
F_8 ( & V_5 -> V_7 . V_26 ) ;
if ( V_5 -> V_7 . V_8 == V_42 ) {
F_17 ( L_13 , V_5 -> V_7 . V_8 ) ;
F_9 ( & V_5 -> V_7 . V_26 ) ;
F_10 ( & V_19 -> V_26 , V_25 ) ;
return - V_43 ;
}
F_9 ( & V_5 -> V_7 . V_26 ) ;
F_10 ( & V_19 -> V_26 , V_25 ) ;
F_18 ( & V_5 -> V_7 , V_44 ) ;
return 0 ;
}
static int F_19 ( T_2 V_15 , T_2 V_41 )
{
if ( V_15 >= V_40 ) {
F_17 ( L_14 , V_15 ) ;
return 0 ;
}
if ( V_41 >= V_27 ) {
F_17 ( L_15 , V_41 ) ;
return 0 ;
}
return 1 ;
}
static T_1 F_20 ( struct V_37 * V_14 , struct V_38 * V_39 ,
const char * V_45 , T_3 V_46 )
{
T_2 V_3 = 0 , V_15 = 0 , V_41 = 0 ;
struct V_20 * V_21 ;
struct V_22 * V_22 ;
int V_36 ;
if ( F_21 ( V_45 , 10 , & V_3 ) < 0 )
return - V_43 ;
V_15 = F_22 ( V_3 ) ;
V_41 = F_23 ( V_3 ) ;
if ( ! F_19 ( V_15 , V_41 ) )
return - V_43 ;
V_21 = F_5 ( V_18 [ V_15 ] . V_17 ) ;
if ( V_21 == NULL ) {
F_24 ( V_14 , L_16 , V_3 ) ;
return - V_47 ;
}
F_4 ( L_17 , V_41 ) ;
if ( ( V_3 / V_27 ) % 2 )
V_22 = F_6 ( V_21 ) -> V_19 -> V_30 ;
else
V_22 = F_6 ( V_21 ) -> V_19 -> V_28 ;
V_36 = F_16 ( V_22 , V_41 ) ;
if ( V_36 < 0 )
return - V_43 ;
F_4 ( L_18 ) ;
return V_46 ;
}
static int F_25 ( T_2 V_15 , T_2 V_41 , enum V_48 V_10 )
{
if ( ! F_19 ( V_15 , V_41 ) ) {
return 0 ;
}
switch ( V_10 ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
break;
default:
F_17 ( L_19 ,
F_26 ( V_10 ) ) ;
return 0 ;
}
return 1 ;
}
static T_1 F_27 ( struct V_37 * V_14 , struct V_38 * V_39 ,
const char * V_45 , T_3 V_46 )
{
struct V_54 * V_54 ;
int V_55 = 0 ;
T_2 V_3 = 0 , V_15 = 0 , V_41 = 0 , V_11 = 0 , V_10 = 0 ;
struct V_20 * V_21 ;
struct V_22 * V_22 ;
struct V_4 * V_5 ;
struct V_19 * V_19 ;
int V_56 ;
unsigned long V_25 ;
if ( sscanf ( V_45 , L_20 , & V_3 , & V_55 , & V_11 , & V_10 ) != 4 )
return - V_43 ;
V_15 = F_22 ( V_3 ) ;
V_41 = F_23 ( V_3 ) ;
F_4 ( L_21 ,
V_3 , V_15 , V_41 ) ;
F_4 ( L_22 ,
V_55 , V_11 , V_10 ) ;
if ( ! F_25 ( V_15 , V_41 , V_10 ) )
return - V_43 ;
V_21 = F_5 ( V_18 [ V_15 ] . V_17 ) ;
if ( V_21 == NULL ) {
F_24 ( V_14 , L_23 , V_3 ) ;
return - V_47 ;
}
V_22 = F_6 ( V_21 ) ;
V_19 = V_22 -> V_19 ;
if ( V_10 == V_53 )
V_5 = & V_19 -> V_30 -> V_5 [ V_41 ] ;
else
V_5 = & V_19 -> V_28 -> V_5 [ V_41 ] ;
V_54 = F_28 ( V_55 , & V_56 ) ;
if ( ! V_54 )
return - V_43 ;
F_7 ( & V_19 -> V_26 , V_25 ) ;
F_8 ( & V_5 -> V_7 . V_26 ) ;
if ( V_5 -> V_7 . V_8 != V_42 ) {
F_9 ( & V_5 -> V_7 . V_26 ) ;
F_10 ( & V_19 -> V_26 , V_25 ) ;
F_29 ( V_54 ) ;
F_24 ( V_14 , L_24 , V_41 ) ;
return - V_57 ;
}
F_30 ( V_14 , L_25 ,
V_15 , V_41 , V_55 ) ;
F_30 ( V_14 , L_26 ,
V_11 , V_10 , F_26 ( V_10 ) ) ;
V_5 -> V_11 = V_11 ;
V_5 -> V_10 = V_10 ;
V_5 -> V_7 . V_12 = V_54 ;
V_5 -> V_7 . V_8 = V_32 ;
F_9 ( & V_5 -> V_7 . V_26 ) ;
F_10 ( & V_19 -> V_26 , V_25 ) ;
V_5 -> V_7 . V_58 = F_31 ( V_59 , & V_5 -> V_7 , L_27 ) ;
V_5 -> V_7 . V_60 = F_31 ( V_61 , & V_5 -> V_7 , L_28 ) ;
F_32 ( V_5 , V_10 ) ;
return V_46 ;
}
static void F_33 ( int V_62 )
{
struct V_63 * V_8 ;
V_8 = V_64 + V_62 ;
if ( V_62 == 0 )
strcpy ( V_8 -> V_33 , L_29 ) ;
else
snprintf ( V_8 -> V_33 , V_65 + 1 , L_30 , V_62 ) ;
V_8 -> V_39 . V_39 . V_33 = V_8 -> V_33 ;
V_8 -> V_39 . V_39 . V_66 = V_67 ;
V_8 -> V_39 . V_68 = F_14 ;
F_34 ( & V_8 -> V_39 . V_39 ) ;
}
static int F_35 ( void )
{
int V_62 ;
V_64 = F_36 ( V_40 , sizeof( struct V_63 ) ,
V_69 ) ;
if ( V_64 == NULL )
return - V_70 ;
for ( V_62 = 0 ; V_62 < V_40 ; V_62 ++ )
F_33 ( V_62 ) ;
return 0 ;
}
static void F_37 ( void )
{
F_38 ( V_64 ) ;
}
int F_39 ( void )
{
struct V_71 * * V_72 ;
int V_36 , V_24 ;
V_72 = F_36 ( ( V_40 + 5 ) , sizeof( struct V_71 * ) ,
V_69 ) ;
if ( V_72 == NULL )
return - V_70 ;
V_36 = F_35 () ;
if ( V_36 ) {
F_38 ( V_72 ) ;
return V_36 ;
}
* V_72 = & V_73 . V_39 ;
* ( V_72 + 1 ) = & V_74 . V_39 ;
* ( V_72 + 2 ) = & V_75 . V_39 ;
* ( V_72 + 3 ) = & V_76 . V_39 ;
for ( V_24 = 0 ; V_24 < V_40 ; V_24 ++ )
* ( V_72 + V_24 + 4 ) = & ( ( V_64 + V_24 ) -> V_39 . V_39 ) ;
V_77 . V_72 = V_72 ;
return 0 ;
}
void F_40 ( void )
{
F_37 () ;
F_38 ( V_77 . V_72 ) ;
}
