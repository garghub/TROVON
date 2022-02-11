static T_1 F_1 ( int V_1 , char * V_2 )
{
struct V_3 * V_4 = * ( V_5 + V_1 ) ;
struct V_6 * V_7 ;
char * V_8 = V_2 ;
int V_9 = 0 ;
unsigned long V_10 ;
if ( ! V_4 || ! V_2 ) {
F_2 ( L_1 ) ;
return 0 ;
}
V_7 = F_3 ( F_4 ( V_4 ) ) ;
F_5 ( & V_7 -> V_11 , V_10 ) ;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ ) {
struct V_13 * V_14 = & V_7 -> V_14 [ V_9 ] ;
F_6 ( & V_14 -> V_15 . V_11 ) ;
V_2 += sprintf ( V_2 , L_2 ,
( V_1 * V_12 ) + V_9 ,
V_14 -> V_15 . V_16 ) ;
if ( V_14 -> V_15 . V_16 == V_17 ) {
V_2 += sprintf ( V_2 , L_3 ,
V_14 -> V_18 , V_14 -> V_19 ) ;
V_2 += sprintf ( V_2 , L_4 ,
V_14 -> V_15 . V_20 ,
F_7 ( & V_14 -> V_21 -> V_22 ) ) ;
} else {
V_2 += sprintf ( V_2 , L_5 ) ;
V_2 += sprintf ( V_2 , L_6 ) ;
}
V_2 += sprintf ( V_2 , L_7 ) ;
F_8 ( & V_14 -> V_15 . V_11 ) ;
}
F_9 ( & V_7 -> V_11 , V_10 ) ;
return V_2 - V_8 ;
}
static T_1 F_10 ( int V_1 , char * V_2 )
{
char * V_8 = V_2 ;
int V_9 = 0 ;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ ) {
V_2 += sprintf ( V_2 , L_2 ,
( V_1 * V_12 ) + V_9 ,
V_23 ) ;
V_2 += sprintf ( V_2 , L_8 ) ;
V_2 += sprintf ( V_2 , L_7 ) ;
}
return V_2 - V_8 ;
}
static int F_11 ( const char * V_24 )
{
char * V_25 ;
long V_26 ;
int V_27 ;
V_25 = strchr ( V_24 , '.' ) ;
if ( V_25 == NULL )
return 0 ;
V_27 = F_12 ( V_25 + 1 , 10 , & V_26 ) ;
if ( V_27 < 0 )
return V_27 ;
return V_26 ;
}
static T_1 F_13 ( struct V_28 * V_22 ,
struct V_29 * V_30 , char * V_2 )
{
char * V_8 = V_2 ;
int V_1 ;
V_2 += sprintf ( V_2 ,
L_9 ) ;
V_1 = F_11 ( V_30 -> V_30 . V_24 ) ;
if ( V_1 < 0 )
V_2 += F_10 ( V_1 , V_2 ) ;
else
V_2 += F_1 ( V_1 , V_2 ) ;
return V_2 - V_8 ;
}
static T_1 F_14 ( struct V_28 * V_22 , struct V_29 * V_30 ,
char * V_2 )
{
char * V_8 = V_2 ;
V_2 += sprintf ( V_2 , L_10 , V_12 * V_31 ) ;
return V_2 - V_8 ;
}
static int F_15 ( struct V_6 * V_7 , T_2 V_32 )
{
struct V_13 * V_14 = & V_7 -> V_14 [ V_32 ] ;
unsigned long V_10 ;
F_2 ( L_11 ) ;
F_5 ( & V_7 -> V_11 , V_10 ) ;
F_6 ( & V_14 -> V_15 . V_11 ) ;
if ( V_14 -> V_15 . V_16 == V_33 ) {
F_16 ( L_12 , V_14 -> V_15 . V_16 ) ;
F_8 ( & V_14 -> V_15 . V_11 ) ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
return - V_34 ;
}
F_8 ( & V_14 -> V_15 . V_11 ) ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
F_17 ( & V_14 -> V_15 , V_35 ) ;
return 0 ;
}
static int F_18 ( T_2 V_1 , T_2 V_32 )
{
if ( V_1 >= V_31 ) {
F_16 ( L_13 , V_1 ) ;
return 0 ;
}
if ( V_32 >= V_12 ) {
F_16 ( L_14 , V_32 ) ;
return 0 ;
}
return 1 ;
}
static T_1 F_19 ( struct V_28 * V_22 , struct V_29 * V_30 ,
const char * V_36 , T_3 V_37 )
{
T_2 V_38 = 0 , V_1 = 0 , V_32 = 0 ;
struct V_39 * V_40 ;
int V_27 ;
if ( F_20 ( V_36 , 10 , & V_38 ) < 0 )
return - V_34 ;
V_1 = F_21 ( V_38 ) ;
V_32 = F_22 ( V_38 ) ;
if ( ! F_18 ( V_1 , V_32 ) )
return - V_34 ;
V_40 = F_4 ( * ( V_5 + V_1 ) ) ;
if ( V_40 == NULL ) {
F_23 ( V_22 , L_15 , V_38 ) ;
return - V_41 ;
}
V_27 = F_15 ( F_3 ( V_40 ) , V_32 ) ;
if ( V_27 < 0 )
return - V_34 ;
F_2 ( L_16 ) ;
return V_37 ;
}
static int F_24 ( T_2 V_1 , T_2 V_32 , enum V_42 V_18 )
{
if ( ! F_18 ( V_1 , V_32 ) ) {
return 0 ;
}
switch ( V_18 ) {
case V_43 :
case V_44 :
case V_45 :
case V_46 :
break;
default:
F_16 ( L_17 ,
F_25 ( V_18 ) ) ;
return 0 ;
}
return 1 ;
}
static T_1 F_26 ( struct V_28 * V_22 , struct V_29 * V_30 ,
const char * V_36 , T_3 V_37 )
{
struct V_47 * V_47 ;
int V_48 = 0 ;
T_2 V_38 = 0 , V_1 = 0 , V_32 = 0 , V_19 = 0 , V_18 = 0 ;
struct V_39 * V_40 ;
struct V_6 * V_7 ;
struct V_13 * V_14 ;
int V_49 ;
unsigned long V_10 ;
if ( sscanf ( V_36 , L_18 , & V_38 , & V_48 , & V_19 , & V_18 ) != 4 )
return - V_34 ;
V_1 = F_21 ( V_38 ) ;
V_32 = F_22 ( V_38 ) ;
F_2 ( L_19 ,
V_38 , V_1 , V_32 ) ;
F_2 ( L_20 ,
V_48 , V_19 , V_18 ) ;
if ( ! F_24 ( V_1 , V_32 , V_18 ) )
return - V_34 ;
V_40 = F_4 ( * ( V_5 + V_1 ) ) ;
if ( V_40 == NULL ) {
F_23 ( V_22 , L_21 , V_38 ) ;
return - V_41 ;
}
V_7 = F_3 ( V_40 ) ;
V_14 = & V_7 -> V_14 [ V_32 ] ;
V_47 = F_27 ( V_48 , & V_49 ) ;
if ( ! V_47 )
return - V_34 ;
F_5 ( & V_7 -> V_11 , V_10 ) ;
F_6 ( & V_14 -> V_15 . V_11 ) ;
if ( V_14 -> V_15 . V_16 != V_33 ) {
F_8 ( & V_14 -> V_15 . V_11 ) ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
F_28 ( V_47 ) ;
F_23 ( V_22 , L_22 , V_32 ) ;
return - V_34 ;
}
F_29 ( V_22 , L_23 ,
V_1 , V_32 , V_48 ) ;
F_29 ( V_22 , L_24 ,
V_19 , V_18 , F_25 ( V_18 ) ) ;
V_14 -> V_19 = V_19 ;
V_14 -> V_18 = V_18 ;
V_14 -> V_15 . V_20 = V_47 ;
V_14 -> V_15 . V_16 = V_23 ;
F_8 ( & V_14 -> V_15 . V_11 ) ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
V_14 -> V_15 . V_50 = F_30 ( V_51 , & V_14 -> V_15 , L_25 ) ;
V_14 -> V_15 . V_52 = F_30 ( V_53 , & V_14 -> V_15 , L_26 ) ;
F_31 ( V_14 , V_18 ) ;
return V_37 ;
}
static void F_32 ( int V_54 )
{
struct V_55 * V_16 ;
V_16 = V_56 + V_54 ;
if ( V_54 == 0 )
strcpy ( V_16 -> V_24 , L_27 ) ;
else
snprintf ( V_16 -> V_24 , V_57 + 1 , L_28 , V_54 ) ;
V_16 -> V_30 . V_30 . V_24 = V_16 -> V_24 ;
V_16 -> V_30 . V_30 . V_58 = V_59 ;
V_16 -> V_30 . V_60 = F_13 ;
F_33 ( & V_16 -> V_30 . V_30 ) ;
}
static int F_34 ( void )
{
int V_54 ;
V_56 = F_35 ( V_31 , sizeof( struct V_55 ) ,
V_61 ) ;
if ( V_56 == NULL )
return - V_62 ;
for ( V_54 = 0 ; V_54 < V_31 ; V_54 ++ )
F_32 ( V_54 ) ;
return 0 ;
}
static void F_36 ( void )
{
F_37 ( V_56 ) ;
}
int F_38 ( void )
{
struct V_63 * * V_64 ;
int V_27 , V_9 ;
V_64 = F_35 ( ( V_31 + 5 ) , sizeof( struct V_63 * ) ,
V_61 ) ;
if ( V_64 == NULL )
return - V_62 ;
V_27 = F_34 () ;
if ( V_27 ) {
F_37 ( V_64 ) ;
return V_27 ;
}
* V_64 = & V_65 . V_30 ;
* ( V_64 + 1 ) = & V_66 . V_30 ;
* ( V_64 + 2 ) = & V_67 . V_30 ;
* ( V_64 + 3 ) = & V_68 . V_30 ;
for ( V_9 = 0 ; V_9 < V_31 ; V_9 ++ )
* ( V_64 + V_9 + 4 ) = & ( ( V_56 + V_9 ) -> V_30 . V_30 ) ;
V_69 . V_64 = V_64 ;
return 0 ;
}
void F_39 ( void )
{
F_36 () ;
F_37 ( V_69 . V_64 ) ;
}
