static void F_1 ( void * V_1 , void * V_2 ,
T_1 * V_3 , int V_4 , long V_5 , void * V_6 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
F_2 ( & V_8 -> V_9 ) ;
F_3 ( & V_8 -> V_10 ) ;
F_4 ( V_8 ) ;
}
static int F_5 ( T_2 * V_11 )
{
int V_12 ;
struct V_7 * V_8 =
(struct V_7 * ) F_6 ( sizeof( struct V_7 ) ) ;
if ( V_8 == NULL )
goto V_12;
V_8 -> V_9 . V_13 = V_14 ;
V_8 -> V_9 . V_15 = V_14 ;
V_8 -> V_9 . V_16 = V_14 ;
V_8 -> V_9 . V_17 = V_14 ;
V_8 -> V_9 . V_18 = V_14 ;
V_8 -> V_9 . V_19 = 0 ;
V_8 -> V_9 . V_20 = 0 ;
V_12 = F_7 ( & V_8 -> V_9 ,
V_21 , sizeof( V_22 ) ) ;
if ( V_12 != V_23 )
goto V_12;
V_8 -> V_10 . V_13 = V_14 ;
V_8 -> V_10 . V_15 = V_14 ;
V_8 -> V_10 . V_16 = V_14 ;
V_8 -> V_10 . V_17 = V_14 ;
V_8 -> V_10 . V_18 = V_14 ;
V_8 -> V_10 . V_19 = 0 ;
V_8 -> V_10 . V_20 = 0 ;
V_12 = F_8 ( & V_8 -> V_10 , V_24 ,
V_21 , sizeof( V_22 ) ) ;
if ( V_12 != V_23 )
goto V_12;
F_9 ( V_25 , V_11 , & V_11 -> V_26 ) ;
if ( V_27 == - 1 )
{
F_10 ( V_28 ) ;
if ( V_27 == - 1 )
V_27 =
F_11 ( V_25 ,
0 , NULL , NULL , NULL , F_1 ) ;
F_12 ( V_28 ) ;
if ( V_27 == - 1 )
goto V_12;
}
F_13 ( & V_11 -> V_26 , V_27 , V_8 ) ;
return 1 ;
V_12:
if ( V_8 ) F_4 ( V_8 ) ;
return 0 ;
}
static void F_14 ( T_2 * V_11 )
{
F_15 ( V_25 , V_11 , & V_11 -> V_26 ) ;
}
static int F_16 ( T_2 * V_11 , unsigned char * V_29 ,
unsigned int V_30 , unsigned char * V_31 , unsigned int V_32 )
{
int V_12 = V_23 ;
struct V_7 * V_8 =
(struct V_7 * ) F_17 ( & V_11 -> V_26 ,
V_27 ) ;
if ( V_8 == NULL )
return - 1 ;
V_8 -> V_10 . V_17 = V_31 ;
V_8 -> V_10 . V_19 = V_32 ;
V_8 -> V_10 . V_18 = V_29 ;
V_8 -> V_10 . V_20 = V_30 ;
if ( V_32 > 0 )
V_12 = F_18 ( & V_8 -> V_10 , V_33 ) ;
if ( V_12 != V_23 )
return - 1 ;
#ifdef F_19
fprintf ( V_34 , L_1 ,
V_32 , V_30 - V_8 -> V_10 . V_20 ,
( V_32 != V_30 - V_8 -> V_10 . V_20 ) ? L_2 : L_3 ) ;
#endif
return V_30 - V_8 -> V_10 . V_20 ;
}
static int F_20 ( T_2 * V_11 , unsigned char * V_29 ,
unsigned int V_30 , unsigned char * V_31 , unsigned int V_32 )
{
int V_12 = V_23 ;
struct V_7 * V_8 =
(struct V_7 * ) F_17 ( & V_11 -> V_26 ,
V_27 ) ;
if ( V_8 == NULL )
return 0 ;
V_8 -> V_9 . V_17 = V_31 ;
V_8 -> V_9 . V_19 = V_32 ;
V_8 -> V_9 . V_18 = V_29 ;
V_8 -> V_9 . V_20 = V_30 ;
if ( V_32 > 0 )
V_12 = F_21 ( & V_8 -> V_9 , V_33 ) ;
if ( V_12 != V_23 )
return - 1 ;
#ifdef F_19
fprintf ( V_34 , L_4 ,
V_32 , V_30 - V_8 -> V_9 . V_20 ,
( V_32 != V_30 - V_8 -> V_9 . V_20 ) ? L_2 : L_3 ) ;
#endif
return V_30 - V_8 -> V_9 . V_20 ;
}
T_3 * F_22 ( void )
{
T_3 * V_35 = & V_36 ;
#ifdef F_23
if ( ! V_37 )
{
#if F_24 ( V_38 ) || F_24 ( V_39 )
V_40 = F_25 ( NULL , L_5 , NULL , 0 ) ;
if ( ! V_40 )
{
V_40 = F_25 ( NULL , L_6 , NULL , 0 ) ;
if ( V_40 )
{
F_26 () ;
}
}
#else
V_40 = F_25 ( NULL , L_7 , NULL , 0 ) ;
#endif
if ( V_40 != NULL )
{
V_41
= ( V_42 ) F_27 ( V_40 ,
L_8 ) ;
V_43
= ( V_44 ) F_27 ( V_40 ,
L_9 ) ;
V_45
= ( V_46 ) F_27 ( V_40 ,
L_10 ) ;
V_47
= ( V_48 ) F_27 ( V_40 ,
L_11 ) ;
V_49
= ( V_50 ) F_27 ( V_40 ,
L_12 ) ;
V_51
= ( V_52 ) F_27 ( V_40 ,
L_13 ) ;
V_53
= ( V_54 ) F_27 ( V_40 ,
L_14 ) ;
V_37 ++ ;
}
}
#endif
#if F_24 ( V_55 ) || F_24 ( F_23 )
V_35 = & V_56 ;
#endif
return ( V_35 ) ;
}
static int
F_28 ( T_4 V_57 )
{
if ( V_43 )
return ( V_43 ( V_57 ) ) ;
else
return ( V_58 ) ;
}
static int
F_29 ( T_4 V_57 , int V_59 )
{
if ( V_45 )
return ( V_45 ( V_57 , V_59 ) ) ;
else
return ( V_58 ) ;
}
static int
F_30 ( T_4 V_57 , const char * V_60 , int V_61 )
{
if ( V_47 )
return ( V_47 ( V_57 , V_60 , V_61 ) ) ;
else
return ( V_58 ) ;
}
static int
F_31 ( T_4 V_57 )
{
if ( V_49 )
return ( V_49 ( V_57 ) ) ;
else
return ( V_58 ) ;
}
static int
F_32 ( T_4 V_57 , int V_59 )
{
if ( V_51 )
return ( V_51 ( V_57 , V_59 ) ) ;
else
return ( V_58 ) ;
}
static int
F_33 ( T_4 V_57 , int V_62 ,
const char * V_60 , int V_61 )
{
if ( V_53 )
return ( V_53 ( V_57 , V_62 , V_60 , V_61 ) ) ;
else
return ( V_58 ) ;
}
