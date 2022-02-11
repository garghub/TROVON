void F_1 ( T_1 V_1 , const char * V_2 , ... )
{
struct V_3 V_4 ;
T_2 args ;
va_start ( args , V_2 ) ;
V_4 . V_2 = V_2 ;
V_4 . V_5 = & args ;
if ( V_1 & V_6 )
F_2 ( L_1 , & V_4 ) ;
va_end ( args ) ;
}
static struct V_7 * F_3 ( struct V_8 * V_9 ,
T_3 * V_10 ,
T_1 V_11 ,
T_3 V_12 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_7 * V_17 = NULL ;
T_3 V_18 ;
if ( F_4 ( ! V_11 , L_2 , V_19 ) )
return NULL ;
if ( V_11 > ( V_20 * 4 ) ) {
F_1 ( V_21 , L_3 ,
V_19 , V_11 ) ;
V_11 = V_20 * 4 ;
}
V_11 -= V_12 ;
V_17 = F_5 ( V_11 + V_22 ) ;
if ( V_17 == NULL )
return NULL ;
V_18 = ( V_12 + V_22 ) ;
F_6 ( V_17 , V_11 ) ;
memcpy ( ( V_17 -> V_23 ) , ( V_10 + V_18 ) , V_17 -> V_24 ) ;
V_14 = F_7 ( V_17 ) ;
V_16 = (struct V_15 * ) V_14 -> V_25 ;
V_16 -> V_26 = F_8 ( V_10 ) ;
V_16 -> V_27 = F_9 ( V_9 -> V_28 ) ;
return V_17 ;
}
int F_10 ( struct V_8 * V_9 , T_4 V_29 )
{
T_3 * V_30 = NULL , V_12 = 0 ;
T_1 V_31 , V_32 = 0 , V_33 = 0 ;
T_5 V_34 = 0 , V_35 ;
struct V_7 * V_17 = NULL ;
V_31 = 0 ;
do {
V_30 = & V_9 -> V_36 [ V_31 ] ;
V_34 = * ( T_5 * ) & V_30 [ 0 ] ;
V_35 = * ( T_5 * ) & V_30 [ 2 ] ;
V_33 = F_11 ( V_30 , V_35 ) ;
V_32 = F_12 ( V_30 , V_35 ) ;
if ( V_33 == V_37 || V_33 == V_38 )
V_12 = F_13 ( V_30 ,
V_35 ) ;
switch ( V_33 ) {
case V_39 :
F_14 ( V_9 , ( V_30 + V_35 ) ) ;
break;
case V_37 :
V_17 = F_3 ( V_9 ,
( V_30 + V_35 ) ,
V_32 ,
V_12 ) ;
if ( V_17 == NULL )
goto V_40;
F_15 ( V_9 , V_17 ) ;
break;
case V_38 :
F_14 ( V_9 , ( V_30 + V_35 ) ) ;
break;
default:
F_1 ( V_21 , L_4 ,
V_19 , V_33 ) ;
goto V_40;
}
V_31 += V_34 ;
V_29 -= V_34 ;
} while ( V_29 > 0 );
return 0 ;
V_40:
return - V_41 ;
}
static void F_16 ( struct V_8 * V_9 )
{
struct V_42 * V_43 = V_9 -> V_28 ;
T_1 V_44 = V_45 ;
do {
if ( V_43 -> V_46 )
V_44 = V_43 -> V_46 ( V_43 ) ;
F_17 ( & V_9 -> V_47 . V_48 , V_44 ) ;
F_18 ( & V_9 -> V_47 . V_48 ) ;
if ( V_9 -> V_49 )
F_19 ( V_9 ) ;
} while ( F_20 ( & V_9 -> V_47 . V_50 ) == 0 );
F_21 ( & V_9 -> V_47 . V_51 , 0 ) ;
}
struct V_42 * F_22 ( void )
{
struct V_42 * V_43 = NULL ;
struct V_8 * V_9 = NULL ;
T_3 V_52 = 0 ;
V_43 = F_23 ( sizeof( * V_43 ) , V_53 ) ;
if ( ! V_43 )
return NULL ;
V_43 -> V_28 = F_23 ( sizeof( * V_9 ) , V_53 ) ;
if ( V_43 -> V_28 == NULL ) {
F_1 ( V_21 , L_5 ,
V_19 ) ;
F_24 ( V_43 ) ;
return NULL ;
} else {
V_9 = V_43 -> V_28 ;
V_9 -> V_28 = V_43 ;
}
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ )
F_25 ( & V_9 -> V_55 [ V_52 ] ) ;
F_26 ( & V_9 -> V_47 . V_48 ) ;
F_27 ( & V_9 -> V_56 ) ;
F_27 ( & V_9 -> V_57 ) ;
if ( F_28 ( V_9 ,
& V_9 -> V_47 ,
F_16 ,
L_6 ) ) {
F_1 ( V_21 , L_7 , V_19 ) ;
goto V_58;
}
V_9 -> V_49 = true ;
return V_43 ;
V_58:
F_24 ( V_9 ) ;
F_24 ( V_43 ) ;
return NULL ;
}
void F_29 ( struct V_42 * V_43 )
{
struct V_8 * V_9 = V_43 -> V_28 ;
T_3 V_52 ;
F_1 ( V_59 , L_8 , V_19 ) ;
F_30 ( & V_9 -> V_47 ) ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ )
F_31 ( & V_9 -> V_55 [ V_52 ] ) ;
V_9 -> V_49 = false ;
F_24 ( V_9 ) ;
F_24 ( V_43 -> V_60 ) ;
F_24 ( V_43 ) ;
}
static int F_32 ( void )
{
F_1 ( V_61 , L_9 , V_19 ) ;
return 0 ;
}
static void F_33 ( void )
{
F_1 ( V_61 , L_10 , V_19 ) ;
}
