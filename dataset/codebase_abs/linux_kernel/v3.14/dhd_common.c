bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , int V_7 )
{
struct V_5 * V_8 ;
int V_9 = - 1 ;
bool V_10 ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
struct V_13 * V_14 = V_12 -> V_14 ;
if ( ! F_3 ( V_4 , V_7 ) && ! F_4 ( V_4 ) ) {
F_5 ( V_4 , V_7 , V_6 ) ;
return true ;
}
if ( F_3 ( V_4 , V_7 ) )
V_9 = V_7 ;
else if ( F_4 ( V_4 ) ) {
V_8 = F_6 ( V_4 , & V_9 ) ;
if ( V_9 > V_7 )
return false ;
}
if ( V_9 >= 0 ) {
V_10 = F_7 ( V_14 -> V_15 , V_9 ) ;
if ( V_9 == V_7 && ! V_10 )
return false ;
V_8 = V_10 ? F_8 ( V_4 , V_9 ) :
F_9 ( V_4 , V_9 ) ;
if ( V_8 == NULL )
F_10 ( L_1 ,
V_10 ) ;
F_11 ( V_8 ) ;
}
V_8 = F_5 ( V_4 , V_7 , V_6 ) ;
if ( V_8 == NULL )
F_10 ( L_2 ) ;
return V_8 != NULL ;
}
static int F_12 ( char * V_16 , char * V_17 )
{
int V_18 ;
if ( strncmp ( V_16 , L_3 , 2 ) != 0 && strncmp ( V_16 , L_4 , 2 ) != 0 ) {
F_10 ( L_5 ) ;
return - V_19 ;
}
V_16 = V_16 + 2 ;
if ( strlen ( V_16 ) % 2 != 0 ) {
F_10 ( L_6 ) ;
return - V_19 ;
}
for ( V_18 = 0 ; * V_16 != '\0' ; V_18 ++ ) {
unsigned long V_20 ;
char V_21 [ 3 ] ;
strncpy ( V_21 , V_16 , 2 ) ;
V_21 [ 2 ] = '\0' ;
if ( F_13 ( V_21 , 16 , & V_20 ) )
return - V_19 ;
V_17 [ V_18 ] = ( V_22 ) V_20 ;
V_16 += 2 ;
}
return V_18 ;
}
static void
F_14 ( struct V_23 * V_24 , char * V_25 , int V_26 ,
int V_27 )
{
unsigned long V_20 ;
char * V_28 ;
char * V_29 = NULL , * V_30 = NULL ;
T_1 V_31 ;
struct V_32 V_33 ;
V_29 = F_15 ( V_25 , V_34 ) ;
if ( ! V_29 )
goto V_35;
V_30 = V_29 ;
V_28 = F_16 ( & V_29 , L_7 ) ;
if ( V_28 == NULL ) {
F_10 ( L_8 ) ;
goto V_35;
}
V_33 . V_36 = 0 ;
if ( ! F_13 ( V_28 , 0 , & V_20 ) )
V_33 . V_36 = F_17 ( ( V_37 ) V_20 ) ;
V_33 . V_26 = F_17 ( V_26 ) ;
V_31 = F_18 ( V_24 , L_9 , & V_33 ,
sizeof( V_33 ) ) ;
if ( V_31 )
F_10 ( L_10 , V_31 ) ;
V_31 = F_19 ( V_24 , L_11 , V_27 ) ;
if ( V_31 )
F_10 ( L_12 , V_31 ) ;
V_35:
F_20 ( V_30 ) ;
}
static void F_21 ( struct V_23 * V_24 , char * V_25 )
{
struct V_38 * V_39 ;
unsigned long V_20 ;
int V_40 ;
T_1 V_31 ;
V_37 V_41 ;
V_37 V_42 ;
char * V_28 [ 8 ] , * V_43 = NULL ;
int V_18 = 0 ;
char * V_29 = NULL , * V_30 = NULL ;
V_29 = F_15 ( V_25 , V_34 ) ;
if ( ! V_29 )
goto V_35;
V_30 = V_29 ;
V_43 = F_22 ( V_44 , V_34 ) ;
if ( ! V_43 )
goto V_35;
V_28 [ V_18 ] = F_16 ( & V_29 , L_7 ) ;
while ( V_28 [ V_18 ] ) {
V_18 ++ ;
if ( V_18 >= 8 ) {
F_10 ( L_13 ) ;
goto V_35;
}
V_28 [ V_18 ] = F_16 ( & V_29 , L_7 ) ;
}
if ( V_18 != 6 ) {
F_10 ( L_14 , V_18 ) ;
goto V_35;
}
V_39 = (struct V_38 * ) V_43 ;
V_39 -> V_36 = 0 ;
if ( ! F_13 ( V_28 [ 0 ] , 0 , & V_20 ) )
V_39 -> V_36 = F_17 ( ( V_37 ) V_20 ) ;
V_39 -> V_45 = 0 ;
if ( ! F_13 ( V_28 [ 1 ] , 0 , & V_20 ) )
V_39 -> V_45 = F_17 ( ( V_37 ) V_20 ) ;
V_39 -> type = 0 ;
if ( ! F_13 ( V_28 [ 2 ] , 0 , & V_20 ) )
V_39 -> type = F_17 ( ( V_37 ) V_20 ) ;
V_39 -> V_46 . V_47 . V_48 = 0 ;
if ( ! F_13 ( V_28 [ 3 ] , 0 , & V_20 ) )
V_39 -> V_46 . V_47 . V_48 = F_17 ( ( V_37 ) V_20 ) ;
V_41 = F_12 ( V_28 [ 4 ] ,
( char * ) V_39 -> V_46 . V_47 . V_49 ) ;
V_42 = F_12 ( V_28 [ 5 ] ,
( char * ) & V_39 -> V_46 . V_47 . V_49 [ V_41 ] ) ;
if ( V_41 != V_42 ) {
F_10 ( L_15 ) ;
goto V_35;
}
V_39 -> V_46 . V_47 . V_50 = F_17 ( V_41 ) ;
V_40 = F_23 ( struct V_38 ,
V_46 . V_47 . V_49 ) ;
V_40 += V_41 + V_42 ;
V_31 = F_18 ( V_24 , L_16 , V_39 ,
V_40 ) ;
if ( V_31 )
F_10 ( L_17 , V_31 ) ;
V_35:
F_20 ( V_30 ) ;
F_20 ( V_43 ) ;
}
int F_24 ( struct V_23 * V_24 )
{
T_2 V_51 [ V_52 ] ;
V_22 V_43 [ V_53 ] ;
char * V_54 ;
T_1 V_31 ;
V_31 = F_25 ( V_24 , L_18 , V_24 -> V_55 ,
sizeof( V_24 -> V_55 ) ) ;
if ( V_31 < 0 ) {
F_10 ( L_19 ,
V_31 ) ;
goto V_56;
}
memcpy ( V_24 -> V_14 -> V_57 , V_24 -> V_55 , sizeof( V_24 -> V_14 -> V_57 ) ) ;
memset ( V_43 , 0 , sizeof( V_43 ) ) ;
strcpy ( V_43 , L_20 ) ;
V_31 = F_25 ( V_24 , L_20 , V_43 , sizeof( V_43 ) ) ;
if ( V_31 < 0 ) {
F_10 ( L_21 ,
V_31 ) ;
goto V_56;
}
V_54 = ( char * ) V_43 ;
F_16 ( & V_54 , L_22 ) ;
F_10 ( L_23 , V_43 ) ;
V_54 = strrchr ( V_43 , ' ' ) + 1 ;
F_26 ( V_24 -> V_14 -> V_58 , V_54 , sizeof( V_24 -> V_14 -> V_58 ) ) ;
V_31 = F_19 ( V_24 , L_24 ,
V_59 ) ;
if ( V_31 ) {
F_10 ( L_25 , V_31 ) ;
goto V_56;
}
V_31 = F_19 ( V_24 , L_26 , 1 ) ;
if ( V_31 ) {
F_10 ( L_27 , V_31 ) ;
goto V_56;
}
V_31 = F_25 ( V_24 , L_28 , V_51 ,
V_52 ) ;
if ( V_31 ) {
F_10 ( L_29 , V_31 ) ;
goto V_56;
}
F_27 ( V_51 , V_60 ) ;
V_31 = F_18 ( V_24 , L_28 , V_51 ,
V_52 ) ;
if ( V_31 ) {
F_10 ( L_30 , V_31 ) ;
goto V_56;
}
V_31 = F_28 ( V_24 , V_61 ,
V_62 ) ;
if ( V_31 ) {
F_10 ( L_31 ,
V_31 ) ;
goto V_56;
}
V_31 = F_28 ( V_24 , V_63 ,
V_64 ) ;
if ( V_31 ) {
F_10 ( L_32 ,
V_31 ) ;
goto V_56;
}
F_21 ( V_24 , V_65 ) ;
F_14 ( V_24 , V_65 ,
0 , true ) ;
V_31 = F_29 ( V_24 -> V_14 -> V_12 ) ;
V_56:
return V_31 ;
}
void F_30 ( const char * V_66 , const char * V_67 , ... )
{
struct V_68 V_69 = {
. V_67 = V_67 ,
} ;
T_3 args ;
va_start ( args , V_67 ) ;
V_69 . V_70 = & args ;
F_31 ( L_33 , V_66 , & V_69 ) ;
F_32 ( V_66 , & V_69 ) ;
va_end ( args ) ;
}
void F_33 ( V_37 V_71 , const char * V_66 , const char * V_67 , ... )
{
struct V_68 V_69 = {
. V_67 = V_67 ,
} ;
T_3 args ;
va_start ( args , V_67 ) ;
V_69 . V_70 = & args ;
if ( V_72 & V_71 )
F_34 ( L_34 , V_66 , & V_69 ) ;
F_35 ( V_71 , V_66 , & V_69 ) ;
va_end ( args ) ;
}
