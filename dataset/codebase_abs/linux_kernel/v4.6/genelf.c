static void
F_1 ( struct V_1 * V_2 ,
unsigned long T_1 V_3 ,
const void * T_2 V_3 ,
T_3 T_4 V_3 )
{
int V_4 ;
T_3 V_5 = sizeof( V_2 -> V_6 ) ;
T_5 V_7 ;
V_4 = F_2 ( L_1 , V_8 ) ;
if ( V_4 == - 1 )
F_3 ( 1 , L_2 ) ;
V_7 = F_4 ( V_4 , V_2 -> V_6 , V_5 ) ;
F_5 ( V_4 ) ;
if ( V_7 != ( T_5 ) V_5 )
memset ( V_2 -> V_6 , 0 , V_5 ) ;
}
static void
F_1 ( struct V_1 * V_2 ,
unsigned long T_1 V_3 ,
const void * T_2 ,
T_3 T_4 )
{
if ( sizeof( V_2 -> V_6 ) < V_9 )
F_6 ( 1 , L_3 ) ;
F_7 ( T_2 , T_4 , ( unsigned char * ) V_2 -> V_6 ) ;
}
static void
F_1 ( struct V_1 * V_2 , unsigned long T_1 , const void * T_2 , T_3 T_4 )
{
T_6 V_10 ;
if ( sizeof( V_2 -> V_6 ) < 16 )
F_6 ( 1 , L_4 ) ;
F_8 ( & V_10 ) ;
F_9 ( & V_10 , & T_1 , sizeof( T_1 ) ) ;
F_9 ( & V_10 , T_2 , T_4 ) ;
F_10 ( ( unsigned char * ) V_2 -> V_6 , & V_10 ) ;
}
int
F_11 ( int V_4 , T_7 T_1 , const char * V_11 ,
const void * T_2 , int T_4 ,
void * V_12 , int V_13 )
{
T_8 * V_14 ;
T_9 * V_15 ;
T_10 * V_16 ;
T_11 * V_17 ;
T_12 * V_18 ;
char * V_19 = NULL ;
int V_20 ;
int V_21 = - 1 ;
if ( F_12 ( V_22 ) == V_23 ) {
F_13 ( L_5 ) ;
return - 1 ;
}
V_14 = F_14 ( V_4 , V_24 , NULL ) ;
if ( ! V_14 ) {
F_13 ( L_6 ) ;
goto error;
}
V_17 = F_15 ( V_14 ) ;
if ( ! V_17 ) {
F_13 ( L_7 ) ;
goto error;
}
V_17 -> V_25 [ V_26 ] = V_27 ;
V_17 -> V_25 [ V_28 ] = V_29 ;
V_17 -> V_30 = V_31 ;
V_17 -> V_32 = V_33 ;
V_17 -> V_34 = V_35 ;
V_17 -> V_36 = V_22 ;
V_17 -> V_37 = 2 ;
V_16 = F_16 ( V_14 ) ;
if ( ! V_16 ) {
F_13 ( L_8 ) ;
goto error;
}
V_15 = F_17 ( V_16 ) ;
if ( ! V_15 ) {
F_13 ( L_9 ) ;
goto error;
}
V_15 -> V_38 = 16 ;
V_15 -> V_39 = 0LL ;
V_15 -> V_40 = ( void * ) T_2 ;
V_15 -> V_41 = V_42 ;
V_15 -> V_43 = T_4 ;
V_15 -> V_44 = V_22 ;
V_18 = F_18 ( V_16 ) ;
if ( ! V_18 ) {
F_13 ( L_10 ) ;
goto error;
}
V_18 -> V_45 = 1 ;
V_18 -> V_46 = V_47 ;
V_18 -> V_48 = V_35 ;
V_18 -> V_49 = V_50 | V_51 ;
V_18 -> V_52 = 0 ;
V_16 = F_16 ( V_14 ) ;
if ( ! V_16 ) {
F_13 ( L_8 ) ;
goto error;
}
V_15 = F_17 ( V_16 ) ;
if ( ! V_15 ) {
F_13 ( L_9 ) ;
goto error;
}
V_15 -> V_38 = 1 ;
V_15 -> V_39 = 0LL ;
V_15 -> V_40 = V_53 ;
V_15 -> V_41 = V_42 ;
V_15 -> V_43 = sizeof( V_53 ) ;
V_15 -> V_44 = V_22 ;
V_18 = F_18 ( V_16 ) ;
if ( ! V_18 ) {
F_13 ( L_10 ) ;
goto error;
}
V_18 -> V_45 = 7 ;
V_18 -> V_46 = V_54 ;
V_18 -> V_49 = 0 ;
V_18 -> V_52 = 0 ;
V_55 [ 1 ] . V_56 = T_4 ;
V_55 [ 1 ] . V_57 = V_35 ;
V_16 = F_16 ( V_14 ) ;
if ( ! V_16 ) {
F_13 ( L_8 ) ;
goto error;
}
V_15 = F_17 ( V_16 ) ;
if ( ! V_15 ) {
F_13 ( L_9 ) ;
goto error;
}
V_15 -> V_38 = 8 ;
V_15 -> V_39 = 0LL ;
V_15 -> V_40 = V_55 ;
V_15 -> V_41 = V_58 ;
V_15 -> V_43 = sizeof( V_55 ) ;
V_15 -> V_44 = V_22 ;
V_18 = F_18 ( V_16 ) ;
if ( ! V_18 ) {
F_13 ( L_10 ) ;
goto error;
}
V_18 -> V_45 = 17 ;
V_18 -> V_46 = V_59 ;
V_18 -> V_49 = 0 ;
V_18 -> V_52 = sizeof( V_60 ) ;
V_18 -> V_61 = 4 ;
V_20 = 2 + strlen ( V_11 ) ;
V_19 = calloc ( 1 , V_20 ) ;
if ( ! V_19 ) {
F_13 ( L_11 ) ;
goto error;
}
strcpy ( V_19 + 1 , V_11 ) ;
V_16 = F_16 ( V_14 ) ;
if ( ! V_16 ) {
F_13 ( L_8 ) ;
goto error;
}
V_15 = F_17 ( V_16 ) ;
if ( ! V_15 ) {
F_13 ( L_9 ) ;
goto error;
}
V_15 -> V_38 = 1 ;
V_15 -> V_39 = 0LL ;
V_15 -> V_40 = V_19 ;
V_15 -> V_41 = V_42 ;
V_15 -> V_43 = V_20 ;
V_15 -> V_44 = V_22 ;
V_18 = F_18 ( V_16 ) ;
if ( ! V_18 ) {
F_13 ( L_10 ) ;
goto error;
}
V_18 -> V_45 = 25 ;
V_18 -> V_46 = V_54 ;
V_18 -> V_49 = 0 ;
V_18 -> V_52 = 0 ;
V_16 = F_16 ( V_14 ) ;
if ( ! V_16 ) {
F_13 ( L_8 ) ;
goto error;
}
V_15 = F_17 ( V_16 ) ;
if ( ! V_15 ) {
F_13 ( L_9 ) ;
goto error;
}
F_1 ( & V_62 , T_1 , T_2 , T_4 ) ;
V_62 . V_63 . V_64 = sizeof( V_62 . V_65 ) ;
V_62 . V_63 . V_66 = sizeof( V_62 . V_6 ) ;
V_62 . V_63 . type = V_67 ;
strcpy ( V_62 . V_65 , L_12 ) ;
V_15 -> V_38 = 4 ;
V_15 -> V_39 = 0LL ;
V_15 -> V_40 = & V_62 ;
V_15 -> V_41 = V_42 ;
V_15 -> V_43 = sizeof( V_62 ) ;
V_15 -> V_44 = V_22 ;
V_18 = F_18 ( V_16 ) ;
if ( ! V_18 ) {
F_13 ( L_10 ) ;
goto error;
}
V_18 -> V_45 = 33 ;
V_18 -> V_46 = V_68 ;
V_18 -> V_48 = 0x0 ;
V_18 -> V_49 = V_51 ;
V_18 -> V_69 = sizeof( V_62 ) ;
V_18 -> V_52 = 0 ;
if ( V_12 && V_13 ) {
V_21 = F_19 ( V_14 , T_1 , V_12 , V_13 ) ;
if ( V_21 )
goto error;
} else {
if ( F_20 ( V_14 , V_24 ) < 0 ) {
F_13 ( L_13 ) ;
goto error;
}
}
V_21 = 0 ;
error:
( void ) F_21 ( V_14 ) ;
free ( V_19 ) ;
return V_21 ;
}
int main ( int V_70 , char * * V_71 )
{
int V_72 , V_4 , V_73 ;
while ( ( V_72 = F_22 ( V_70 , V_71 , L_14 ) ) != - 1 ) {
switch ( V_72 ) {
case 'o' :
V_74 . V_75 = V_76 ;
break;
case 'h' :
printf ( L_15 ) ;
return 0 ;
default:
F_6 ( 1 , L_16 ) ;
}
}
V_4 = F_2 ( V_74 . V_75 , V_77 | V_78 | V_79 , 0666 ) ;
if ( V_4 == - 1 )
F_3 ( 1 , L_17 , V_74 . V_75 ) ;
V_73 = F_11 ( V_4 , L_18 , V_80 , sizeof( V_80 ) ) ;
F_5 ( V_4 ) ;
if ( V_73 != 0 )
F_23 ( V_74 . V_75 ) ;
return V_73 ;
}
