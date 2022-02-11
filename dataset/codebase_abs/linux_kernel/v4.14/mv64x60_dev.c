static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 V_6 [ 2 ] ;
struct V_7 V_8 ;
const T_2 * V_9 ;
struct V_1 * V_10 , * V_11 ;
int V_12 ;
V_9 = F_2 ( V_2 , L_1 , NULL ) ;
V_10 = F_3 ( * V_9 ) ;
if ( ! V_10 )
return - V_13 ;
V_12 = F_4 ( V_10 , 0 , & V_6 [ 0 ] ) ;
F_5 ( V_10 ) ;
if ( V_12 )
return V_12 ;
V_9 = F_2 ( V_2 , L_2 , NULL ) ;
V_11 = F_3 ( * V_9 ) ;
if ( ! V_11 )
return - V_13 ;
V_12 = F_4 ( V_11 , 0 , & V_6 [ 1 ] ) ;
F_5 ( V_11 ) ;
if ( V_12 )
return V_12 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_4 = F_6 ( V_14 , 0 ) ;
if ( ! V_4 )
return - V_15 ;
V_12 = F_7 ( V_4 , V_6 , 2 ) ;
if ( V_12 )
goto error;
V_12 = F_8 ( V_4 , & V_8 , sizeof( V_8 ) ) ;
if ( V_12 )
goto error;
V_12 = F_9 ( V_4 ) ;
if ( V_12 )
goto error;
return 0 ;
error:
F_10 ( V_4 ) ;
return V_12 ;
}
static int T_1 F_11 ( struct V_1 * V_2 , int V_16 )
{
struct V_5 V_6 [ 5 ] ;
struct V_17 V_8 ;
struct V_3 * V_4 ;
const unsigned int * V_18 ;
const T_2 * V_9 ;
struct V_1 * V_19 , * V_20 ;
int V_12 ;
int V_21 ;
if ( V_16 == 0 && ( V_12 = F_1 ( V_2 ) ) )
return V_12 ;
memset ( V_6 , 0 , sizeof( V_6 ) ) ;
V_12 = F_4 ( V_2 , 0 , & V_6 [ 0 ] ) ;
if ( V_12 )
return V_12 ;
F_12 ( V_2 , 0 , & V_6 [ 4 ] ) ;
V_9 = F_2 ( V_2 , L_3 , NULL ) ;
V_19 = F_3 ( * V_9 ) ;
if ( ! V_19 )
return - V_13 ;
F_12 ( V_19 , 0 , & V_6 [ 3 ] ) ;
V_12 = F_4 ( V_19 , 0 , & V_6 [ 1 ] ) ;
F_5 ( V_19 ) ;
if ( V_12 )
return V_12 ;
V_9 = F_2 ( V_2 , L_4 , NULL ) ;
V_20 = F_3 ( * V_9 ) ;
if ( ! V_20 )
return - V_13 ;
V_12 = F_4 ( V_20 , 0 , & V_6 [ 2 ] ) ;
F_5 ( V_20 ) ;
if ( V_12 )
return V_12 ;
V_18 = F_2 ( V_2 , L_5 , NULL ) ;
if ( ! V_18 )
return - V_13 ;
V_21 = * ( int * ) V_18 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_22 = 1 ;
V_8 . V_23 = 40 ;
V_18 = F_2 ( V_2 , L_6 , NULL ) ;
if ( V_18 )
V_8 . V_23 = * V_18 ;
V_18 = F_2 ( V_20 , L_7 , NULL ) ;
if ( V_18 )
V_8 . V_24 = * V_18 ;
V_8 . V_25 = 8 ;
V_8 . V_26 = 'n' ;
V_8 . V_27 = 'n' ;
V_18 = F_2 ( V_2 , L_8 , NULL ) ;
if ( V_18 )
V_8 . V_28 = * V_18 ;
V_18 = F_2 ( V_2 , L_9 , NULL ) ;
if ( V_18 )
V_8 . V_29 = * V_18 ;
V_18 = F_2 ( V_2 , L_10 , NULL ) ;
if ( V_18 )
V_8 . V_30 = * V_18 ;
V_18 = F_2 ( V_2 , L_11 , NULL ) ;
if ( V_18 )
V_8 . V_31 = * V_18 ;
V_18 = F_2 ( V_20 , L_12 , NULL ) ;
if ( V_18 )
V_8 . V_32 = * V_18 ;
V_8 . V_33 = 1 ;
V_18 = F_2 ( V_20 , L_13 , NULL ) ;
if ( V_18 )
V_8 . V_34 = * V_18 ;
V_18 = F_2 ( V_20 , L_14 , NULL ) ;
if ( V_18 )
V_8 . V_35 = * V_18 ;
V_4 = F_6 ( V_36 , V_21 ) ;
if ( ! V_4 )
return - V_15 ;
V_4 -> V_37 . V_38 = F_13 ( 32 ) ;
V_12 = F_7 ( V_4 , V_6 , 5 ) ;
if ( V_12 )
goto error;
V_12 = F_8 ( V_4 , & V_8 , sizeof( V_8 ) ) ;
if ( V_12 )
goto error;
V_12 = F_9 ( V_4 ) ;
if ( V_12 )
goto error;
return 0 ;
error:
F_10 ( V_4 ) ;
return V_12 ;
}
static struct V_3 * T_1 F_14 (
struct V_1 * V_2 , int V_16 )
{
struct V_3 * V_4 ;
struct V_5 V_6 [ 2 ] ;
int V_12 ;
V_12 = F_4 ( V_2 , 0 , & V_6 [ 0 ] ) ;
if ( V_12 )
return F_15 ( V_12 ) ;
V_6 [ 1 ] . V_39 = V_6 [ 0 ] . V_39 + 0x4 ;
V_6 [ 1 ] . V_40 = V_6 [ 0 ] . V_39 + 0x84 - 1 ;
V_6 [ 1 ] . V_41 = V_42 ;
if ( V_16 == 0 ) {
V_4 = F_16 ( L_15 , - 1 , & V_6 [ 1 ] , 1 ) ;
if ( F_17 ( V_4 ) )
return V_4 ;
}
V_4 = F_16 ( V_43 , V_16 ,
& V_6 [ 0 ] , 1 ) ;
return V_4 ;
}
static int T_1 F_18 ( struct V_1 * V_2 , int V_16 ,
struct V_3 * V_44 )
{
struct V_5 V_6 [ 1 ] ;
struct V_45 V_8 ;
struct V_3 * V_4 ;
struct V_1 * V_46 ;
const T_3 * V_47 ;
const int * V_18 ;
const T_2 * V_9 ;
int V_12 ;
memset ( V_6 , 0 , sizeof( V_6 ) ) ;
F_12 ( V_2 , 0 , & V_6 [ 0 ] ) ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_48 = V_44 ;
V_18 = F_2 ( V_2 , L_16 , NULL ) ;
if ( ! V_18 )
return - V_13 ;
V_8 . V_21 = * V_18 ;
V_47 = F_19 ( V_2 ) ;
if ( V_47 )
memcpy ( V_8 . V_47 , V_47 , 6 ) ;
V_18 = F_2 ( V_2 , L_17 , NULL ) ;
if ( V_18 )
V_8 . V_49 = * V_18 ;
V_18 = F_2 ( V_2 , L_18 , NULL ) ;
if ( V_18 )
V_8 . V_50 = * V_18 ;
V_18 = F_2 ( V_2 , L_19 , NULL ) ;
if ( V_18 )
V_8 . V_51 = * V_18 ;
V_18 = F_2 ( V_2 , L_20 , NULL ) ;
if ( V_18 )
V_8 . V_52 = * V_18 ;
V_18 = F_2 ( V_2 , L_21 , NULL ) ;
if ( V_18 )
V_8 . V_53 = * V_18 ;
V_18 = F_2 ( V_2 , L_22 , NULL ) ;
if ( V_18 )
V_8 . V_54 = * V_18 ;
V_18 = F_2 ( V_2 , L_23 , NULL ) ;
if ( V_18 )
V_8 . V_55 = * V_18 ;
V_9 = F_2 ( V_2 , L_24 , NULL ) ;
if ( ! V_9 )
return - V_13 ;
V_46 = F_3 ( * V_9 ) ;
if ( V_46 == NULL )
return - V_13 ;
V_18 = F_2 ( V_46 , L_16 , NULL ) ;
if ( V_18 )
V_8 . V_56 = F_20 ( * V_18 ) ;
F_5 ( V_46 ) ;
V_4 = F_6 ( V_57 , V_16 ) ;
if ( ! V_4 )
return - V_15 ;
V_4 -> V_37 . V_38 = F_13 ( 32 ) ;
V_12 = F_7 ( V_4 , V_6 , 1 ) ;
if ( V_12 )
goto error;
V_12 = F_8 ( V_4 , & V_8 , sizeof( V_8 ) ) ;
if ( V_12 )
goto error;
V_12 = F_9 ( V_4 ) ;
if ( V_12 )
goto error;
return 0 ;
error:
F_10 ( V_4 ) ;
return V_12 ;
}
static int T_1 F_21 ( struct V_1 * V_2 , int V_16 )
{
struct V_5 V_6 [ 2 ] ;
struct V_3 * V_4 ;
struct V_58 V_8 ;
const unsigned int * V_18 ;
int V_12 ;
memset ( V_6 , 0 , sizeof( V_6 ) ) ;
V_12 = F_4 ( V_2 , 0 , & V_6 [ 0 ] ) ;
if ( V_12 )
return V_12 ;
F_12 ( V_2 , 0 , & V_6 [ 1 ] ) ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_59 = 8 ;
V_18 = F_2 ( V_2 , L_25 , NULL ) ;
if ( V_18 )
V_8 . V_59 = * V_18 ;
V_8 . V_60 = 3 ;
V_18 = F_2 ( V_2 , L_26 , NULL ) ;
if ( V_18 )
V_8 . V_60 = * V_18 ;
V_8 . V_61 = 1000 ;
V_4 = F_6 ( V_62 , V_16 ) ;
if ( ! V_4 )
return - V_15 ;
V_12 = F_7 ( V_4 , V_6 , 2 ) ;
if ( V_12 )
goto error;
V_12 = F_8 ( V_4 , & V_8 , sizeof( V_8 ) ) ;
if ( V_12 )
goto error;
V_12 = F_9 ( V_4 ) ;
if ( V_12 )
goto error;
return 0 ;
error:
F_10 ( V_4 ) ;
return V_12 ;
}
static int T_1 F_22 ( struct V_1 * V_2 , int V_16 )
{
struct V_5 V_6 ;
struct V_3 * V_4 ;
struct V_63 V_8 ;
const unsigned int * V_18 ;
int V_12 ;
V_12 = F_4 ( V_2 , 0 , & V_6 ) ;
if ( V_12 )
return V_12 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_61 = 10 ;
V_2 = F_23 ( V_2 ) ;
if ( ! V_2 )
return - V_13 ;
V_18 = F_2 ( V_2 , L_14 , NULL ) ;
F_5 ( V_2 ) ;
if ( ! V_18 )
return - V_13 ;
V_8 . V_64 = * V_18 / 1000000 ;
V_4 = F_6 ( V_65 , V_16 ) ;
if ( ! V_4 )
return - V_15 ;
V_12 = F_7 ( V_4 , & V_6 , 1 ) ;
if ( V_12 )
goto error;
V_12 = F_8 ( V_4 , & V_8 , sizeof( V_8 ) ) ;
if ( V_12 )
goto error;
V_12 = F_9 ( V_4 ) ;
if ( V_12 )
goto error;
return 0 ;
error:
F_10 ( V_4 ) ;
return V_12 ;
}
static int T_1 F_24 ( void )
{
struct V_1 * V_2 , * V_66 ;
struct V_3 * V_4 ;
int V_16 , V_67 ;
int V_12 ;
V_16 = 0 ;
F_25 (np, NULL, L_27 ) {
V_12 = F_11 ( V_2 , V_16 ++ ) ;
if ( V_12 )
F_26 ( V_68 L_28
L_29 ,
V_2 , V_12 ) ;
}
V_16 = 0 ;
V_67 = 0 ;
F_25 (np, NULL, L_30 ) {
V_4 = F_14 ( V_2 , V_16 ++ ) ;
if ( F_17 ( V_4 ) ) {
V_12 = F_27 ( V_4 ) ;
F_26 ( V_68 L_28
L_31 ,
V_2 , V_12 ) ;
continue;
}
F_28 (np, np2) {
if ( ! F_29 ( V_66 ,
L_32 ) )
continue;
V_12 = F_18 ( V_66 , V_67 ++ , V_4 ) ;
if ( V_12 )
F_26 ( V_68 L_33
L_34
L_35 ,
V_66 , V_12 ) ;
}
}
V_16 = 0 ;
F_25 (np, L_36 , L_37 ) {
V_12 = F_21 ( V_2 , V_16 ++ ) ;
if ( V_12 )
F_26 ( V_68 L_38
L_39 ,
V_2 , V_12 ) ;
}
V_2 = F_30 ( V_2 , NULL , L_40 ) ;
if ( V_2 ) {
if ( ( V_12 = F_22 ( V_2 , V_16 ) ) )
F_26 ( V_68 L_28
L_41 ,
V_2 , V_12 ) ;
F_5 ( V_2 ) ;
}
F_25 (np, NULL, L_42 )
F_31 ( V_2 , V_69 , NULL ) ;
return 0 ;
}
static int T_1 F_32 ( void )
{
struct V_1 * V_2 = NULL ;
const char * V_18 ;
V_18 = F_2 ( V_70 , L_43 , NULL ) ;
if ( V_18 == NULL )
goto V_71;
V_2 = F_33 ( V_18 ) ;
if ( ! V_2 )
goto V_71;
if ( ! F_29 ( V_2 , L_27 ) )
goto V_71;
V_18 = F_2 ( V_2 , L_5 , NULL ) ;
if ( ! V_18 )
goto V_71;
F_34 ( L_44 , * ( int * ) V_18 , NULL ) ;
V_71:
return 0 ;
}
