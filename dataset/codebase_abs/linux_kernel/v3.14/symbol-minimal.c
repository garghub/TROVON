static bool F_1 ( int V_1 )
{
const int V_2 = 1 ;
T_1 * V_3 = ( T_1 * ) & V_2 ;
int V_4 ;
if ( V_3 [ 0 ] == 1 )
V_4 = V_5 ;
else
V_4 = V_6 ;
return V_4 != V_1 ;
}
static int F_2 ( void * V_7 , T_2 V_8 , void * V_9 ,
T_2 V_10 , bool V_11 )
{
struct {
T_3 V_12 ;
T_3 V_13 ;
T_3 V_14 ;
} * V_15 ;
void * V_16 ;
V_16 = V_7 ;
while ( V_16 < ( V_7 + V_8 ) ) {
const char * V_17 ;
T_2 V_18 , V_19 ;
V_15 = V_16 ;
if ( V_11 ) {
V_15 -> V_12 = F_3 ( V_15 -> V_12 ) ;
V_15 -> V_13 = F_3 ( V_15 -> V_13 ) ;
V_15 -> V_14 = F_3 ( V_15 -> V_14 ) ;
}
V_18 = F_4 ( V_15 -> V_12 ) ;
V_19 = F_4 ( V_15 -> V_13 ) ;
V_16 += sizeof( * V_15 ) ;
V_17 = V_16 ;
V_16 += V_18 ;
if ( V_15 -> V_14 == V_20 &&
V_15 -> V_12 == sizeof( L_1 ) ) {
if ( memcmp ( V_17 , L_1 , sizeof( L_1 ) ) == 0 ) {
T_2 V_21 = F_5 ( V_10 , V_19 ) ;
memcpy ( V_9 , V_16 , V_21 ) ;
memset ( V_9 + V_21 , 0 , V_10 - V_21 ) ;
return 0 ;
}
}
V_16 += V_19 ;
}
return - 1 ;
}
int F_6 ( const char * T_4 V_22 ,
char * T_5 V_22 ,
T_2 V_10 V_22 )
{
return - 1 ;
}
int F_7 ( const char * T_4 , void * V_9 , T_2 V_10 )
{
T_6 * V_23 ;
int V_24 = - 1 ;
bool V_11 = false ;
T_1 V_25 [ V_26 ] ;
T_2 V_27 ;
void * V_28 ;
int V_29 ;
V_23 = fopen ( T_4 , L_2 ) ;
if ( V_23 == NULL )
return - 1 ;
if ( fread ( V_25 , sizeof( V_25 ) , 1 , V_23 ) != 1 )
goto V_30;
if ( memcmp ( V_25 , V_31 , V_32 ) ||
V_25 [ V_33 ] != V_34 )
goto V_30;
V_11 = F_1 ( V_25 [ V_35 ] ) ;
fseek ( V_23 , 0 , V_36 ) ;
if ( V_25 [ V_37 ] == V_38 ) {
T_7 V_39 ;
T_8 * V_40 ;
if ( fread ( & V_39 , sizeof( V_39 ) , 1 , V_23 ) != 1 )
goto V_30;
if ( V_11 ) {
V_39 . V_41 = F_3 ( V_39 . V_41 ) ;
V_39 . V_42 = F_8 ( V_39 . V_42 ) ;
V_39 . V_43 = F_8 ( V_39 . V_43 ) ;
}
V_27 = V_39 . V_42 * V_39 . V_43 ;
V_28 = malloc ( V_27 ) ;
if ( V_28 == NULL )
goto V_30;
fseek ( V_23 , V_39 . V_41 , V_36 ) ;
if ( fread ( V_28 , V_27 , 1 , V_23 ) != 1 )
goto V_44;
for ( V_29 = 0 , V_40 = V_28 ; V_29 < V_39 . V_43 ; V_29 ++ , V_40 ++ ) {
void * V_45 ;
if ( V_11 ) {
V_40 -> V_46 = F_3 ( V_40 -> V_46 ) ;
V_40 -> V_47 = F_3 ( V_40 -> V_47 ) ;
V_40 -> V_48 = F_3 ( V_40 -> V_48 ) ;
}
if ( V_40 -> V_46 != V_49 )
continue;
V_27 = V_40 -> V_48 ;
V_45 = realloc ( V_28 , V_27 ) ;
if ( V_45 == NULL )
goto V_44;
V_28 = V_45 ;
fseek ( V_23 , V_40 -> V_47 , V_36 ) ;
if ( fread ( V_28 , V_27 , 1 , V_23 ) != 1 )
goto V_44;
V_24 = F_2 ( V_28 , V_27 , V_9 , V_10 , V_11 ) ;
if ( V_24 == 0 )
V_24 = V_10 ;
break;
}
} else {
T_9 V_39 ;
T_10 * V_40 ;
if ( fread ( & V_39 , sizeof( V_39 ) , 1 , V_23 ) != 1 )
goto V_30;
if ( V_11 ) {
V_39 . V_41 = F_9 ( V_39 . V_41 ) ;
V_39 . V_42 = F_8 ( V_39 . V_42 ) ;
V_39 . V_43 = F_8 ( V_39 . V_43 ) ;
}
V_27 = V_39 . V_42 * V_39 . V_43 ;
V_28 = malloc ( V_27 ) ;
if ( V_28 == NULL )
goto V_30;
fseek ( V_23 , V_39 . V_41 , V_36 ) ;
if ( fread ( V_28 , V_27 , 1 , V_23 ) != 1 )
goto V_44;
for ( V_29 = 0 , V_40 = V_28 ; V_29 < V_39 . V_43 ; V_29 ++ , V_40 ++ ) {
void * V_45 ;
if ( V_11 ) {
V_40 -> V_46 = F_3 ( V_40 -> V_46 ) ;
V_40 -> V_47 = F_9 ( V_40 -> V_47 ) ;
V_40 -> V_48 = F_9 ( V_40 -> V_48 ) ;
}
if ( V_40 -> V_46 != V_49 )
continue;
V_27 = V_40 -> V_48 ;
V_45 = realloc ( V_28 , V_27 ) ;
if ( V_45 == NULL )
goto V_44;
V_28 = V_45 ;
fseek ( V_23 , V_40 -> V_47 , V_36 ) ;
if ( fread ( V_28 , V_27 , 1 , V_23 ) != 1 )
goto V_44;
V_24 = F_2 ( V_28 , V_27 , V_9 , V_10 , V_11 ) ;
if ( V_24 == 0 )
V_24 = V_10 ;
break;
}
}
V_44:
free ( V_28 ) ;
V_30:
fclose ( V_23 ) ;
return V_24 ;
}
int F_10 ( const char * T_4 , void * V_50 , T_2 V_10 )
{
int V_51 ;
int V_24 = - 1 ;
struct V_52 V_53 ;
T_2 V_27 ;
void * V_28 ;
V_51 = F_11 ( T_4 , V_54 ) ;
if ( V_51 < 0 )
return - 1 ;
if ( F_12 ( V_51 , & V_53 ) < 0 )
goto V_30;
V_27 = V_53 . V_55 ;
V_28 = malloc ( V_27 ) ;
if ( V_28 == NULL )
goto V_30;
if ( F_13 ( V_51 , V_28 , V_27 ) != ( V_56 ) V_27 )
goto V_44;
V_24 = F_2 ( V_28 , V_27 , V_50 , V_10 , false ) ;
V_44:
free ( V_28 ) ;
V_30:
F_14 ( V_51 ) ;
return V_24 ;
}
int F_15 ( struct V_57 * V_58 , struct V_59 * V_59 V_22 ,
const char * V_17 ,
enum V_60 type )
{
int V_51 = F_11 ( V_17 , V_54 ) ;
if ( V_51 < 0 )
return - 1 ;
V_58 -> V_17 = F_16 ( V_17 ) ;
if ( ! V_58 -> V_17 )
goto V_61;
V_58 -> V_51 = V_51 ;
V_58 -> type = type ;
return 0 ;
V_61:
F_14 ( V_51 ) ;
return - 1 ;
}
bool F_17 ( struct V_57 * V_58 V_22 )
{
return true ;
}
bool F_18 ( struct V_57 * V_58 V_22 )
{
return false ;
}
void F_19 ( struct V_57 * V_58 )
{
F_20 ( & V_58 -> V_17 ) ;
F_14 ( V_58 -> V_51 ) ;
}
int F_21 ( struct V_59 * V_59 V_22 ,
struct V_57 * V_58 V_22 ,
struct V_62 * V_62 V_22 ,
T_11 T_12 V_22 )
{
return 0 ;
}
int F_22 ( struct V_59 * V_59 , struct V_62 * V_62 V_22 ,
struct V_57 * V_58 ,
struct V_57 * T_13 V_22 ,
T_11 T_12 V_22 ,
int T_14 V_22 )
{
unsigned char * V_50 [ V_63 ] ;
if ( F_7 ( V_58 -> V_17 , V_50 , V_63 ) > 0 ) {
F_23 ( V_59 , V_50 ) ;
return 1 ;
}
return 0 ;
}
int F_24 ( int V_51 V_22 , bool T_15 V_22 ,
T_16 T_17 V_22 , void * V_2 V_22 ,
bool * T_18 V_22 )
{
return - 1 ;
}
int F_25 ( struct V_64 * T_19 V_22 )
{
return - 1 ;
}
void F_26 ( struct V_64 * T_19 V_22 )
{
}
int F_27 ( const char * T_20 V_22 ,
const char * T_21 V_22 )
{
return - 1 ;
}
void F_28 ( void )
{
}
