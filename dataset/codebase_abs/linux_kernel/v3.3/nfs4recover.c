static int
F_1 ( const struct V_1 * * V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 () ;
if ( ! V_3 )
return - V_4 ;
V_3 -> V_5 = 0 ;
V_3 -> V_6 = 0 ;
* V_2 = F_3 ( V_3 ) ;
F_4 ( V_3 ) ;
return 0 ;
}
static void
F_5 ( const struct V_1 * V_7 )
{
F_6 ( V_7 ) ;
}
static void
F_7 ( char * V_8 , char * V_9 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < 16 ; V_10 ++ ) {
unsigned char V_11 = V_9 [ V_10 ] ;
* V_8 ++ = '0' + ( ( V_11 & 0xf0 ) >> 4 ) + ( V_11 >= 0xa0 ) * ( 'a' - '9' - 1 ) ;
* V_8 ++ = '0' + ( V_11 & 0x0f ) + ( ( V_11 & 0x0f ) >= 0x0a ) * ( 'a' - '9' - 1 ) ;
}
* V_8 = '\0' ;
}
T_1
F_8 ( char * V_12 , struct V_13 * V_14 )
{
struct V_13 V_15 ;
struct V_16 V_17 ;
struct V_18 V_19 ;
T_1 V_20 = V_21 ;
F_9 ( L_1 ,
V_14 -> V_22 , V_14 -> V_23 ) ;
V_17 . V_24 = V_25 ;
V_17 . V_26 = F_10 ( L_2 , 0 , V_27 ) ;
if ( F_11 ( V_17 . V_26 ) )
goto V_28;
V_15 . V_22 = F_12 ( V_17 . V_26 ) ;
V_15 . V_23 = F_13 ( V_15 . V_22 , V_29 ) ;
if ( V_15 . V_23 == NULL )
goto V_8;
F_14 ( & V_19 , V_14 -> V_23 , V_14 -> V_22 ) ;
if ( F_15 ( & V_17 , & V_19 , V_19 . V_30 , V_15 . V_23 ) )
goto V_8;
F_7 ( V_12 , V_15 . V_23 ) ;
V_20 = V_31 ;
V_8:
F_16 ( V_15 . V_23 ) ;
F_17 ( V_17 . V_26 ) ;
V_28:
return V_20 ;
}
void F_18 ( struct V_32 * V_33 )
{
const struct V_1 * V_34 ;
char * V_12 = V_33 -> V_35 ;
struct V_36 * V_37 , * V_36 ;
int V_20 ;
F_9 ( L_3 , V_12 ) ;
if ( V_33 -> V_38 )
return;
V_33 -> V_38 = 1 ;
if ( ! V_39 )
return;
V_20 = F_1 ( & V_34 ) ;
if ( V_20 < 0 )
return;
V_37 = V_39 -> V_40 . V_36 ;
F_19 ( & V_37 -> V_41 -> V_42 ) ;
V_36 = F_20 ( V_12 , V_37 , V_43 - 1 ) ;
if ( F_11 ( V_36 ) ) {
V_20 = F_21 ( V_36 ) ;
goto V_44;
}
if ( V_36 -> V_41 )
goto V_45;
V_20 = F_22 ( V_39 ) ;
if ( V_20 )
goto V_45;
V_20 = F_23 ( V_37 -> V_41 , V_36 , V_46 ) ;
F_24 ( V_39 ) ;
V_45:
F_25 ( V_36 ) ;
V_44:
F_26 ( & V_37 -> V_41 -> V_42 ) ;
if ( V_20 == 0 )
F_27 ( V_39 , 0 ) ;
else
F_28 ( V_47 L_4
L_5
L_6 , V_20 ,
V_48 ) ;
F_5 ( V_34 ) ;
}
static int
F_29 ( void * V_49 , const char * V_50 , int V_51 ,
T_2 V_52 , T_3 V_53 , unsigned int V_54 )
{
struct V_55 * V_56 = V_49 ;
struct V_57 * V_58 ;
if ( V_51 != V_43 - 1 )
return 0 ;
V_58 = F_13 ( sizeof( struct V_57 ) , V_29 ) ;
if ( V_58 == NULL )
return - V_4 ;
memcpy ( V_58 -> V_50 , V_50 , V_43 - 1 ) ;
V_58 -> V_50 [ V_43 - 1 ] = '\0' ;
F_30 ( & V_58 -> V_59 , V_56 ) ;
return 0 ;
}
static int
F_31 ( T_4 * V_60 )
{
const struct V_1 * V_34 ;
struct V_36 * V_37 = V_39 -> V_40 . V_36 ;
F_32 ( V_56 ) ;
int V_20 ;
V_20 = F_1 ( & V_34 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_33 ( V_39 , 0 , V_61 ) ;
if ( V_20 < 0 ) {
F_5 ( V_34 ) ;
return V_20 ;
}
V_20 = F_34 ( V_39 , F_29 , & V_56 ) ;
F_35 ( & V_37 -> V_41 -> V_42 , V_62 ) ;
while ( ! F_36 ( & V_56 ) ) {
struct V_57 * V_58 ;
V_58 = F_37 ( V_56 . V_63 , struct V_57 , V_59 ) ;
if ( ! V_20 ) {
struct V_36 * V_36 ;
V_36 = F_20 ( V_58 -> V_50 , V_37 , V_43 - 1 ) ;
if ( F_11 ( V_36 ) ) {
V_20 = F_21 ( V_36 ) ;
break;
}
V_20 = V_60 ( V_37 , V_36 ) ;
F_25 ( V_36 ) ;
}
F_38 ( & V_58 -> V_59 ) ;
F_16 ( V_58 ) ;
}
F_26 ( & V_37 -> V_41 -> V_42 ) ;
F_5 ( V_34 ) ;
return V_20 ;
}
static int
F_39 ( char * V_50 , int V_51 )
{
struct V_36 * V_37 , * V_36 ;
int V_20 ;
F_9 ( L_7 , V_51 , V_50 ) ;
V_37 = V_39 -> V_40 . V_36 ;
F_35 ( & V_37 -> V_41 -> V_42 , V_62 ) ;
V_36 = F_20 ( V_50 , V_37 , V_51 ) ;
if ( F_11 ( V_36 ) ) {
V_20 = F_21 ( V_36 ) ;
goto V_44;
}
V_20 = - V_64 ;
if ( ! V_36 -> V_41 )
goto V_8;
V_20 = F_40 ( V_37 -> V_41 , V_36 ) ;
V_8:
F_25 ( V_36 ) ;
V_44:
F_26 ( & V_37 -> V_41 -> V_42 ) ;
return V_20 ;
}
void
F_41 ( struct V_32 * V_33 )
{
const struct V_1 * V_34 ;
int V_20 ;
if ( ! V_39 || ! V_33 -> V_38 )
return;
V_20 = F_22 ( V_39 ) ;
if ( V_20 )
goto V_8;
V_33 -> V_38 = 0 ;
V_20 = F_1 ( & V_34 ) ;
if ( V_20 < 0 )
goto V_8;
V_20 = F_39 ( V_33 -> V_35 , V_43 - 1 ) ;
F_5 ( V_34 ) ;
if ( V_20 == 0 )
F_27 ( V_39 , 0 ) ;
F_24 ( V_39 ) ;
V_8:
if ( V_20 )
F_28 ( L_8
L_9 , V_43 , V_33 -> V_35 ) ;
return;
}
static int
F_42 ( struct V_36 * V_65 , struct V_36 * V_66 )
{
int V_20 ;
if ( F_43 ( V_66 -> V_67 . V_50 , false ) )
return 0 ;
V_20 = F_40 ( V_65 -> V_41 , V_66 ) ;
if ( V_20 )
F_28 ( L_10 ,
V_66 -> V_67 . V_50 ) ;
return 0 ;
}
void
F_44 ( void ) {
int V_20 ;
if ( ! V_39 )
return;
V_20 = F_22 ( V_39 ) ;
if ( V_20 )
goto V_8;
V_20 = F_31 ( F_42 ) ;
if ( V_20 == 0 )
F_27 ( V_39 , 0 ) ;
F_24 ( V_39 ) ;
V_8:
if ( V_20 )
F_28 ( L_11
L_12 , V_39 -> V_40 . V_36 -> V_67 . V_50 ) ;
}
static int
F_45 ( struct V_36 * V_65 , struct V_36 * V_66 )
{
if ( V_66 -> V_67 . V_22 != V_43 - 1 ) {
F_28 ( L_13 ,
V_66 -> V_67 . V_50 ) ;
return 0 ;
}
F_46 ( V_66 -> V_67 . V_50 ) ;
return 0 ;
}
int
F_47 ( void ) {
int V_20 ;
if ( ! V_39 )
return 0 ;
V_20 = F_31 ( F_45 ) ;
if ( V_20 )
F_28 ( L_14
L_12 , V_39 -> V_40 . V_36 -> V_67 . V_50 ) ;
return V_20 ;
}
void
F_48 ()
{
const struct V_1 * V_34 ;
int V_20 ;
F_28 ( L_15 ,
V_48 ) ;
F_49 ( V_39 ) ;
V_20 = F_1 ( & V_34 ) ;
if ( V_20 < 0 ) {
F_28 ( L_16
L_17 ,
V_20 ) ;
return;
}
V_39 = F_50 ( V_48 , V_68 | V_69 , 0 ) ;
if ( F_11 ( V_39 ) ) {
F_28 ( L_18 ,
V_48 ) ;
V_39 = NULL ;
}
F_5 ( V_34 ) ;
}
void
F_51 ( void )
{
if ( ! V_39 )
return;
F_52 ( V_39 ) ;
V_39 = NULL ;
}
int
F_53 ( char * V_70 )
{
int V_20 ;
struct V_71 V_71 ;
V_20 = F_54 ( V_70 , V_72 , & V_71 ) ;
if ( V_20 )
return V_20 ;
V_20 = - V_73 ;
if ( F_55 ( V_71 . V_36 -> V_41 -> V_74 ) ) {
strcpy ( V_48 , V_70 ) ;
V_20 = 0 ;
}
F_56 ( & V_71 ) ;
return V_20 ;
}
char *
F_57 ( void )
{
return V_48 ;
}
