static int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
T_2 * V_3 ;
T_3 * V_4 ;
T_4 * V_5 ;
int V_6 ;
if( V_1 && ( V_1 -> V_7 == V_8 ) ) return 1 ;
if( ! V_1 || ! V_1 -> V_9 ) {
F_2 ( V_10 , V_11 ) ;
goto V_12;
}
V_6 = F_3 ( V_1 -> V_9 , V_13 , - 1 ) ;
if( V_6 < 0 ) return 1 ;
if( ! ( V_5 = F_4 ( V_1 -> V_9 , V_6 ) ) ||
! ( V_3 = F_5 ( V_5 ) ) ) {
F_2 ( V_10 , V_14 ) ;
goto V_12;
}
for( V_6 = 0 ; V_6 < F_6 ( V_3 ) ; V_6 ++ ) {
V_4 = F_7 ( V_3 , V_6 ) ;
if( ! F_8 ( V_2 , V_4 ) ) {
F_2 ( V_10 , V_15 ) ;
goto V_12;
}
}
F_9 ( V_3 ) ;
return 1 ;
V_12:
return 0 ;
}
static int F_10 ( T_1 * V_1 , T_2 * V_2 , int V_16 )
{
T_5 * V_17 ;
T_6 * V_18 = NULL ;
T_7 * V_19 ;
T_3 * V_4 = NULL ;
int V_6 ;
if( V_1 -> V_7 == V_8 ) return 1 ;
if( ! V_1 || ( ! V_1 -> V_20 && ! V_1 -> V_21 ) ) {
F_2 ( V_22 , V_23 ) ;
goto V_12;
}
if( V_1 -> V_20 ) V_17 = F_11 ( V_1 -> V_20 ) ;
else V_17 = F_12 ( V_1 -> V_21 ) ;
V_6 = - 1 ;
while( ( V_6 = F_13 ( V_17 ,
V_24 , V_6 ) ) >= 0 ) {
V_19 = F_14 ( V_17 , V_6 ) ;
V_18 = F_15 ( F_16 ( V_19 ) ) ;
if ( V_16 )
{
F_17 ( V_17 , V_6 ) ;
V_6 -- ;
}
if( ! V_18 || ! ( V_4 = F_18 () ) ) {
F_2 ( V_22 , V_15 ) ;
goto V_12;
}
V_4 -> V_25 . V_26 = V_18 ;
V_18 = NULL ;
V_4 -> type = V_27 ;
if( ! F_8 ( V_2 , V_4 ) ) {
F_2 ( V_22 , V_15 ) ;
goto V_12;
}
V_4 = NULL ;
}
return 1 ;
V_12:
F_19 ( V_4 ) ;
F_20 ( V_18 ) ;
return 0 ;
}
T_3 * F_21 ( T_8 * V_28 , T_1 * V_1 ,
T_9 * V_29 )
{
return F_22 ( NULL , V_28 , V_1 , V_29 , 0 ) ;
}
T_3 * F_22 ( T_3 * V_30 ,
T_8 * V_28 , T_1 * V_1 ,
T_9 * V_29 , int V_31 )
{
char V_32 = 0 ;
int type ;
T_3 * V_4 = NULL ;
char * V_33 , * V_34 ;
V_33 = V_29 -> V_33 ;
V_34 = V_29 -> V_34 ;
if( ! V_34 )
{
F_2 ( V_35 , V_36 ) ;
return NULL ;
}
if ( V_30 )
V_4 = V_30 ;
else
{
V_4 = F_18 () ;
if( V_4 == NULL )
{
F_2 ( V_35 , V_15 ) ;
return NULL ;
}
}
if( ! F_23 ( V_33 , L_1 ) )
{
V_32 = 1 ;
type = V_27 ;
}
else if( ! F_23 ( V_33 , L_2 ) )
{
V_32 = 1 ;
type = V_37 ;
}
else if( ! F_23 ( V_33 , L_3 ) )
{
V_32 = 1 ;
type = V_38 ;
}
else if( ! F_23 ( V_33 , L_4 ) )
{
T_10 * V_39 ;
if( ! ( V_39 = F_24 ( V_34 , 0 ) ) )
{
F_2 ( V_35 , V_40 ) ;
F_25 ( 2 , L_5 , V_34 ) ;
goto V_12;
}
V_4 -> V_25 . V_41 = V_39 ;
type = V_42 ;
}
else if( ! F_23 ( V_33 , L_6 ) )
{
if ( V_31 )
V_4 -> V_25 . V_43 = F_26 ( V_34 ) ;
else
V_4 -> V_25 . V_43 = F_27 ( V_34 ) ;
if( V_4 -> V_25 . V_43 == NULL )
{
F_2 ( V_35 , V_44 ) ;
F_25 ( 2 , L_5 , V_34 ) ;
goto V_12;
}
type = V_45 ;
}
else if( ! F_23 ( V_33 , L_7 ) )
{
type = V_46 ;
if ( ! F_28 ( V_4 , V_34 , V_1 ) )
{
F_2 ( V_35 , V_47 ) ;
goto V_12;
}
}
else if( ! F_23 ( V_33 , L_8 ) )
{
if ( ! F_29 ( V_4 , V_34 , V_1 ) )
{
F_2 ( V_35 , V_48 ) ;
goto V_12;
}
type = V_49 ;
}
else
{
F_2 ( V_35 , V_50 ) ;
F_25 ( 2 , L_9 , V_33 ) ;
goto V_12;
}
if( V_32 )
{
if( ! ( V_4 -> V_25 . V_26 = F_30 () ) ||
! F_31 ( V_4 -> V_25 . V_26 , ( unsigned char * ) V_34 ,
strlen ( V_34 ) ) )
{
F_2 ( V_35 , V_15 ) ;
goto V_12;
}
}
V_4 -> type = type ;
return V_4 ;
V_12:
F_19 ( V_4 ) ;
return NULL ;
}
static int F_29 ( T_3 * V_4 , char * V_34 , T_1 * V_1 )
{
char * V_51 = NULL , * V_52 ;
int V_53 ;
if ( ! ( V_52 = strchr ( V_34 , ';' ) ) )
return 0 ;
if ( ! ( V_4 -> V_25 . V_54 = F_32 () ) )
return 0 ;
F_33 ( V_4 -> V_25 . V_54 -> V_34 ) ;
if ( ! ( V_4 -> V_25 . V_54 -> V_34 = F_34 ( V_52 + 1 , V_1 ) ) )
return 0 ;
V_53 = V_52 - V_34 ;
V_51 = F_35 ( V_53 + 1 ) ;
strncpy ( V_51 , V_34 , V_53 ) ;
V_51 [ V_53 ] = 0 ;
V_4 -> V_25 . V_54 -> V_55 = F_24 ( V_51 , 0 ) ;
F_36 ( V_51 ) ;
if ( ! V_4 -> V_25 . V_54 -> V_55 )
return 0 ;
return 1 ;
}
static int F_28 ( T_3 * V_4 , char * V_34 , T_1 * V_1 )
{
int V_56 ;
F_37 ( T_9 ) * V_57 ;
T_5 * V_17 ;
if ( ! ( V_17 = F_38 () ) )
return 0 ;
V_57 = F_39 ( V_1 , V_34 ) ;
if ( ! V_57 )
{
F_2 ( V_58 , V_59 ) ;
F_25 ( 2 , L_10 , V_34 ) ;
F_40 ( V_17 ) ;
return 0 ;
}
V_56 = F_41 ( V_17 , V_57 , V_60 ) ;
if ( ! V_56 )
F_40 ( V_17 ) ;
V_4 -> V_25 . V_61 = V_17 ;
return V_56 ;
}
