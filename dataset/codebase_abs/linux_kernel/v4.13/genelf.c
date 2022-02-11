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
static int
F_11 ( T_7 * V_11 , void * V_12 , T_8 V_13 ,
T_8 V_14 , T_8 V_15 )
{
T_9 * V_16 ;
T_10 * V_17 ;
T_11 * V_18 ;
T_8 V_19 = V_14 - V_13 ;
V_17 = F_12 ( V_11 ) ;
if ( ! V_17 ) {
F_13 ( L_5 ) ;
return - 1 ;
}
V_16 = F_14 ( V_17 ) ;
if ( ! V_16 ) {
F_13 ( L_6 ) ;
return - 1 ;
}
V_16 -> V_20 = 8 ;
V_16 -> V_21 = 0LL ;
V_16 -> V_22 = V_12 ;
V_16 -> V_23 = V_24 ;
V_16 -> V_25 = V_19 ;
V_16 -> V_26 = V_27 ;
V_18 = F_15 ( V_17 ) ;
if ( ! V_18 ) {
F_13 ( L_7 ) ;
return - 1 ;
}
V_18 -> V_28 = 104 ;
V_18 -> V_29 = V_30 ;
V_18 -> V_31 = V_15 ;
V_18 -> V_32 = V_33 ;
V_18 -> V_34 = 0 ;
V_17 = F_12 ( V_11 ) ;
if ( ! V_17 ) {
F_13 ( L_5 ) ;
return - 1 ;
}
V_16 = F_14 ( V_17 ) ;
if ( ! V_16 ) {
F_13 ( L_6 ) ;
return - 1 ;
}
V_16 -> V_20 = 4 ;
V_16 -> V_21 = 0LL ;
V_16 -> V_22 = V_12 + V_19 ;
V_16 -> V_23 = V_24 ;
V_16 -> V_25 = V_13 ;
V_16 -> V_26 = V_27 ;
V_18 = F_15 ( V_17 ) ;
if ( ! V_18 ) {
F_13 ( L_7 ) ;
return - 1 ;
}
V_18 -> V_28 = 90 ;
V_18 -> V_29 = V_30 ;
V_18 -> V_31 = V_15 + V_19 ;
V_18 -> V_32 = V_33 ;
V_18 -> V_34 = 0 ;
return 0 ;
}
int
F_16 ( int V_4 , T_8 T_1 , const char * V_35 ,
const void * T_2 , int T_4 ,
void * T_12 V_3 , int T_13 V_3 ,
void * V_12 , T_8 V_13 , T_8 V_14 )
{
T_7 * V_11 ;
T_9 * V_16 ;
T_10 * V_17 ;
T_14 * V_36 ;
T_11 * V_18 ;
T_8 V_37 ;
char * V_38 = NULL ;
int V_39 ;
int V_40 = - 1 ;
if ( F_17 ( V_27 ) == V_41 ) {
F_13 ( L_8 ) ;
return - 1 ;
}
V_11 = F_18 ( V_4 , V_42 , NULL ) ;
if ( ! V_11 ) {
F_13 ( L_9 ) ;
goto error;
}
V_36 = F_19 ( V_11 ) ;
if ( ! V_36 ) {
F_13 ( L_10 ) ;
goto error;
}
V_36 -> V_43 [ V_44 ] = V_45 ;
V_36 -> V_43 [ V_46 ] = V_47 ;
V_36 -> V_48 = V_49 ;
V_36 -> V_50 = V_51 ;
V_36 -> V_52 = V_53 ;
V_36 -> V_54 = V_27 ;
V_36 -> V_55 = V_12 ? 4 : 2 ;
V_17 = F_12 ( V_11 ) ;
if ( ! V_17 ) {
F_13 ( L_5 ) ;
goto error;
}
V_16 = F_14 ( V_17 ) ;
if ( ! V_16 ) {
F_13 ( L_6 ) ;
goto error;
}
V_16 -> V_20 = 16 ;
V_16 -> V_21 = 0LL ;
V_16 -> V_22 = ( void * ) T_2 ;
V_16 -> V_23 = V_24 ;
V_16 -> V_25 = T_4 ;
V_16 -> V_26 = V_27 ;
V_18 = F_15 ( V_17 ) ;
if ( ! V_18 ) {
F_13 ( L_7 ) ;
goto error;
}
V_18 -> V_28 = 1 ;
V_18 -> V_29 = V_30 ;
V_18 -> V_31 = V_53 ;
V_18 -> V_32 = V_56 | V_33 ;
V_18 -> V_34 = 0 ;
if ( V_12 ) {
V_37 = F_20 ( V_53 + T_4 ) ;
V_40 = F_11 ( V_11 , V_12 ,
V_13 , V_14 ,
V_37 ) ;
if ( V_40 )
goto error;
}
V_17 = F_12 ( V_11 ) ;
if ( ! V_17 ) {
F_13 ( L_5 ) ;
goto error;
}
V_16 = F_14 ( V_17 ) ;
if ( ! V_16 ) {
F_13 ( L_6 ) ;
goto error;
}
V_16 -> V_20 = 1 ;
V_16 -> V_21 = 0LL ;
V_16 -> V_22 = V_57 ;
V_16 -> V_23 = V_24 ;
V_16 -> V_25 = sizeof( V_57 ) ;
V_16 -> V_26 = V_27 ;
V_18 = F_15 ( V_17 ) ;
if ( ! V_18 ) {
F_13 ( L_7 ) ;
goto error;
}
V_18 -> V_28 = 7 ;
V_18 -> V_29 = V_58 ;
V_18 -> V_32 = 0 ;
V_18 -> V_34 = 0 ;
V_59 [ 1 ] . V_60 = T_4 ;
V_59 [ 1 ] . V_61 = V_53 ;
V_17 = F_12 ( V_11 ) ;
if ( ! V_17 ) {
F_13 ( L_5 ) ;
goto error;
}
V_16 = F_14 ( V_17 ) ;
if ( ! V_16 ) {
F_13 ( L_6 ) ;
goto error;
}
V_16 -> V_20 = 8 ;
V_16 -> V_21 = 0LL ;
V_16 -> V_22 = V_59 ;
V_16 -> V_23 = V_62 ;
V_16 -> V_25 = sizeof( V_59 ) ;
V_16 -> V_26 = V_27 ;
V_18 = F_15 ( V_17 ) ;
if ( ! V_18 ) {
F_13 ( L_7 ) ;
goto error;
}
V_18 -> V_28 = 17 ;
V_18 -> V_29 = V_63 ;
V_18 -> V_32 = 0 ;
V_18 -> V_34 = sizeof( V_64 ) ;
V_18 -> V_65 = V_12 ? 6 : 4 ;
V_39 = 2 + strlen ( V_35 ) ;
V_38 = calloc ( 1 , V_39 ) ;
if ( ! V_38 ) {
F_13 ( L_11 ) ;
goto error;
}
strcpy ( V_38 + 1 , V_35 ) ;
V_17 = F_12 ( V_11 ) ;
if ( ! V_17 ) {
F_13 ( L_5 ) ;
goto error;
}
V_16 = F_14 ( V_17 ) ;
if ( ! V_16 ) {
F_13 ( L_6 ) ;
goto error;
}
V_16 -> V_20 = 1 ;
V_16 -> V_21 = 0LL ;
V_16 -> V_22 = V_38 ;
V_16 -> V_23 = V_24 ;
V_16 -> V_25 = V_39 ;
V_16 -> V_26 = V_27 ;
V_18 = F_15 ( V_17 ) ;
if ( ! V_18 ) {
F_13 ( L_7 ) ;
goto error;
}
V_18 -> V_28 = 25 ;
V_18 -> V_29 = V_58 ;
V_18 -> V_32 = 0 ;
V_18 -> V_34 = 0 ;
V_17 = F_12 ( V_11 ) ;
if ( ! V_17 ) {
F_13 ( L_5 ) ;
goto error;
}
V_16 = F_14 ( V_17 ) ;
if ( ! V_16 ) {
F_13 ( L_6 ) ;
goto error;
}
F_1 ( & V_66 , T_1 , T_2 , T_4 ) ;
V_66 . V_67 . V_68 = sizeof( V_66 . V_69 ) ;
V_66 . V_67 . V_70 = sizeof( V_66 . V_6 ) ;
V_66 . V_67 . type = V_71 ;
strcpy ( V_66 . V_69 , L_12 ) ;
V_16 -> V_20 = 4 ;
V_16 -> V_21 = 0LL ;
V_16 -> V_22 = & V_66 ;
V_16 -> V_23 = V_24 ;
V_16 -> V_25 = sizeof( V_66 ) ;
V_16 -> V_26 = V_27 ;
V_18 = F_15 ( V_17 ) ;
if ( ! V_18 ) {
F_13 ( L_7 ) ;
goto error;
}
V_18 -> V_28 = 33 ;
V_18 -> V_29 = V_72 ;
V_18 -> V_31 = 0x0 ;
V_18 -> V_32 = V_33 ;
V_18 -> V_73 = sizeof( V_66 ) ;
V_18 -> V_34 = 0 ;
#ifdef F_21
if ( T_12 && T_13 ) {
V_40 = F_22 ( V_11 , T_1 , T_12 , T_13 ) ;
if ( V_40 )
goto error;
} else
#endif
{
if ( F_23 ( V_11 , V_42 ) < 0 ) {
F_13 ( L_13 ) ;
goto error;
}
}
V_40 = 0 ;
error:
( void ) F_24 ( V_11 ) ;
free ( V_38 ) ;
return V_40 ;
}
int main ( int V_74 , char * * V_75 )
{
int V_76 , V_4 , V_77 ;
while ( ( V_76 = F_25 ( V_74 , V_75 , L_14 ) ) != - 1 ) {
switch ( V_76 ) {
case 'o' :
V_78 . V_79 = V_80 ;
break;
case 'h' :
printf ( L_15 ) ;
return 0 ;
default:
F_6 ( 1 , L_16 ) ;
}
}
V_4 = F_2 ( V_78 . V_79 , V_81 | V_82 | V_83 , 0666 ) ;
if ( V_4 == - 1 )
F_3 ( 1 , L_17 , V_78 . V_79 ) ;
V_77 = F_16 ( V_4 , L_18 , V_84 , sizeof( V_84 ) ) ;
F_5 ( V_4 ) ;
if ( V_77 != 0 )
F_26 ( V_78 . V_79 ) ;
return V_77 ;
}
