static int F_1 ( int V_1 , T_1 V_2 , T_2 V_3 )
{
struct V_4 V_5 ;
T_1 V_6 [ 16 ] ;
F_2 ( V_7 ) ;
int V_8 ;
V_5 . V_5 = V_9 ;
V_10:
if ( V_11 ) {
V_6 [ 0 ] = 0x30 ;
V_6 [ 1 ] = V_2 ;
* ( ( T_2 * ) ( & V_6 [ 2 ] ) ) = V_3 ;
V_5 . V_12 = 4 ;
} else {
if ( V_2 > 7 )
return - V_13 ;
memset ( V_6 , 0 , 16 ) ;
V_6 [ 0 ] = V_1 ? 0x10 : 0x00 ;
V_6 [ 1 ] = 0x01 << V_2 ;
* ( ( T_2 * ) & V_6 [ 2 + V_2 * 2 ] ) = V_3 ;
V_5 . V_12 = 14 ;
}
V_5 . V_14 = 16 ;
V_5 . V_15 = V_5 . V_16 = V_6 ;
V_5 . V_17 = 0 ;
V_5 . V_18 = V_19 ;
V_5 . V_20 = & V_7 ;
V_8 = F_3 ( & V_5 ) ;
if ( V_8 )
return V_8 ;
F_4 ( & V_7 ) ;
if ( V_5 . V_17 != 0 && V_11 ) {
F_5 ( V_21 L_1
L_2 ) ;
V_11 = 0 ;
goto V_10;
}
return V_5 . V_17 ;
}
static void F_6 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = F_7 ( V_23 ) ;
F_8 ( V_25 ) ;
}
static int F_9 ( struct V_22 * V_23 , T_3 V_3 )
{
struct V_24 * V_25 = F_7 ( V_23 ) ;
if ( V_3 < V_25 -> V_26 )
V_3 = V_25 -> V_26 ;
if ( V_3 > V_25 -> V_27 )
V_3 = V_25 -> V_27 ;
V_25 -> V_3 = V_3 ;
return F_1 ( V_25 -> V_28 , V_25 -> V_29 , V_3 ) ;
}
static int F_10 ( struct V_22 * V_23 , T_3 * V_3 )
{
struct V_24 * V_25 = F_7 ( V_23 ) ;
* V_3 = V_25 -> V_3 ;
return 0 ;
}
static T_3 F_11 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = F_7 ( V_23 ) ;
return V_25 -> V_26 ;
}
static T_3 F_12 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = F_7 ( V_23 ) ;
return V_25 -> V_27 ;
}
static struct V_24 * F_13 ( struct V_30 * V_31 ,
int V_32 )
{
struct V_24 * V_25 ;
const T_3 * V_33 ;
const T_4 * V_29 ;
const char * V_34 ;
V_25 = F_14 ( sizeof( struct V_24 ) , V_35 ) ;
if ( V_25 == NULL )
return NULL ;
V_25 -> V_36 . V_37 = & V_38 ;
V_34 = F_15 ( V_31 , L_3 , NULL ) ;
if ( V_34 == NULL )
goto V_39;
V_25 -> V_28 = V_32 ;
V_25 -> V_36 . type = V_32 ? V_40 : V_41 ;
V_25 -> V_36 . V_42 = NULL ;
if ( ! strcmp ( V_34 , L_4 ) || ! strcmp ( V_34 , L_5 ) ||
! strcmp ( V_34 , L_6 ) || ! strcmp ( V_34 , L_7 ) ||
! strcmp ( V_34 , L_8 ) )
V_25 -> V_36 . V_42 = L_9 ;
else if ( ! strcmp ( V_34 , L_10 ) || ! strcmp ( V_34 , L_11 ) ||
! strcmp ( V_34 , L_12 ) )
V_25 -> V_36 . V_42 = L_13 ;
else if ( ! strcmp ( V_34 , L_14 ) || ! strcmp ( V_34 , L_15 ) ||
! strcmp ( V_34 , L_16 ) || ! strcmp ( V_34 , L_17 ) ||
! strcmp ( V_34 , L_18 ) )
V_25 -> V_36 . V_42 = L_19 ;
else if ( ! strcmp ( V_34 , L_20 ) || ! strcmp ( V_34 , L_21 ) ||
! strcmp ( V_34 , L_22 ) )
V_25 -> V_36 . V_42 = L_23 ;
else if ( ! strcmp ( V_34 , L_24 ) )
V_25 -> V_36 . V_42 = L_25 ;
else if ( ! strcmp ( V_34 , L_26 ) )
V_25 -> V_36 . V_42 = L_27 ;
else if ( ! strcmp ( V_34 , L_28 ) || ! strcmp ( V_34 , L_29 ) ||
! strcmp ( V_34 , L_30 ) )
V_25 -> V_36 . V_42 = L_31 ;
else if ( ! strcmp ( V_34 , L_32 ) || ! strcmp ( V_34 , L_33 ) ||
! strcmp ( V_34 , L_34 ) )
V_25 -> V_36 . V_42 = L_35 ;
else if ( ! strcmp ( V_34 , L_36 ) )
V_25 -> V_36 . V_42 = L_37 ;
if ( ! strcmp ( V_34 , L_38 ) || ! strcmp ( V_34 , L_39 ) )
V_25 -> V_36 . V_42 = L_40 ;
else if ( ! strcmp ( V_34 , L_41 ) || ! strcmp ( V_34 , L_42 ) )
V_25 -> V_36 . V_42 = L_43 ;
else if ( ! strcmp ( V_34 , L_44 ) || ! strcmp ( V_34 , L_45 ) )
V_25 -> V_36 . V_42 = L_35 ;
else if ( ! strcmp ( V_34 , L_46 ) )
V_25 -> V_36 . V_42 = L_47 ;
else if ( ! strcmp ( V_34 , L_48 ) )
V_25 -> V_36 . V_42 = L_49 ;
if ( V_25 -> V_36 . V_42 == NULL )
goto V_39;
V_33 = F_15 ( V_31 , L_50 , NULL ) ;
if ( V_33 == NULL )
goto V_39;
V_25 -> V_26 = * V_33 ;
V_33 = F_15 ( V_31 , L_51 , NULL ) ;
if ( V_33 == NULL )
goto V_39;
V_25 -> V_27 = * V_33 ;
V_29 = F_15 ( V_31 , L_52 , NULL ) ;
if ( V_29 == NULL )
goto V_39;
V_25 -> V_29 = * V_29 ;
if ( F_16 ( & V_25 -> V_36 ) )
goto V_39;
return V_25 ;
V_39:
F_8 ( V_25 ) ;
return NULL ;
}
static int T_5 F_17 ( void )
{
struct V_30 * V_43 , * V_44 , * V_45 ;
if ( ! F_18 () )
return - V_46 ;
V_43 = F_19 ( NULL , L_53 ) ;
if ( V_43 == NULL )
return - V_46 ;
for ( V_44 = NULL ; ( V_44 = F_20 ( V_43 , V_44 ) ) != NULL ; )
if ( ! strcmp ( V_44 -> V_42 , L_54 ) ||
F_21 ( V_44 , L_55 ) )
break;
for ( V_45 = NULL ;
V_44 && ( V_45 = F_20 ( V_44 , V_45 ) ) != NULL ; ) {
struct V_24 * V_25 ;
V_25 = F_13 ( V_45 , 0 ) ;
if ( V_25 == NULL ) {
F_5 ( V_21 L_56
L_57 , V_45 -> V_42 ) ;
continue;
}
F_22 ( & V_25 -> V_47 , & V_48 ) ;
}
F_23 ( V_44 ) ;
for ( V_44 = NULL ; ( V_44 = F_20 ( V_43 , V_44 ) ) != NULL ; )
if ( ! strcmp ( V_44 -> V_42 , L_58 ) )
break;
for ( V_45 = NULL ;
V_44 && ( V_45 = F_20 ( V_44 , V_45 ) ) != NULL ; ) {
struct V_24 * V_25 ;
V_25 = F_13 ( V_45 , 1 ) ;
if ( V_25 == NULL ) {
F_5 ( V_21 L_56
L_59 , V_45 -> V_42 ) ;
continue;
}
F_22 ( & V_25 -> V_47 , & V_48 ) ;
}
F_23 ( V_44 ) ;
F_23 ( V_43 ) ;
return 0 ;
}
static void T_6 F_24 ( void )
{
struct V_24 * V_25 ;
while ( ! F_25 ( & V_48 ) ) {
V_25 = F_26 ( V_48 . V_49 , struct V_24 , V_47 ) ;
F_27 ( & V_25 -> V_47 ) ;
F_28 ( & V_25 -> V_36 ) ;
}
}
