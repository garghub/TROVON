static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> type == V_5 &&
V_4 -> V_6 ==
V_7 ? 0 : 1 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> type == V_5 &&
V_4 -> V_6 ==
V_8 ? 0 : 1 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> type == V_9 &&
V_10 . V_11 <
V_10 . V_12 ? 0 : 1 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> type == V_9 &&
V_10 . V_11 ==
V_10 . V_12 ? 0 : 1 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_13 * V_14 = F_7 ( V_2 ) ;
return V_4 -> type == V_15 &&
F_8 ( V_14 ) &&
F_9 ( V_14 ) &&
F_10 ( V_14 ) == V_16 &&
! V_14 -> V_17 ? 0 : 1 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_13 * V_14 = F_7 ( V_2 ) ;
return V_4 -> type == V_15 &&
F_12 ( V_14 ) &&
F_9 ( V_14 ) &&
F_13 ( V_14 ) == V_16 &&
! V_14 -> V_17 &&
! V_10 . V_18 ? 0 : 1 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_13 * V_14 = F_7 ( V_2 ) ;
return V_4 -> type == V_15 &&
F_12 ( V_14 ) &&
F_9 ( V_14 ) &&
F_13 ( V_14 ) == V_16 &&
! V_14 -> V_17 &&
V_10 . V_18 == 1 ? 0 : 1 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_13 * V_14 = F_7 ( V_2 ) ;
return V_4 -> type == V_15 &&
F_8 ( V_14 ) &&
F_9 ( V_14 ) &&
F_10 ( V_14 ) == V_19 &&
! V_14 -> V_17 ? 0 : 1 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> type == V_20 &&
V_4 -> V_21 == V_22 &&
V_4 -> V_6 == V_23 ? 0 : 1 ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_18 ( & V_10 . V_24 , V_2 ) ;
while ( ( V_2 = F_19 ( & V_10 . V_24 ) ) != NULL )
if ( F_20 ( V_2 ) )
break;
}
static int F_21 ( struct V_1 * V_2 )
{
F_22 ( & V_10 . V_25 ,
V_26 + V_27 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
V_10 . V_11 = 0 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
V_10 . V_11 ++ ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
V_10 . V_18 = 0 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
V_10 . V_18 ++ ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_28 = 1 ;
struct V_1 * V_29 = F_28 ( NULL , V_2 -> V_30 , V_31 ,
sizeof( struct V_32 ) ) ;
if ( ! V_29 )
goto V_33;
F_29 ( V_29 , V_31 , 0 , 0 , V_34 ) ;
F_30 ( V_29 , V_35 , 127 ) ;
V_28 = F_31 ( V_29 , V_2 -> V_30 -> V_36 , V_2 -> V_30 -> V_36 ) ;
if ( F_32 ( V_28 ) )
goto free;
F_17 ( V_29 ) ;
V_33:
return V_28 ;
free:
F_33 ( V_29 ) ;
goto V_33;
}
static int F_34 ( struct V_1 * V_2 )
{
T_1 V_37 [ V_38 ] , V_17 ;
int V_28 = 1 ;
struct V_1 * V_29 = F_28 ( NULL , V_2 -> V_30 , V_31 ,
sizeof( struct V_32 ) ) ;
if ( ! V_29 )
goto V_33;
V_28 = 0 ;
F_35 ( V_2 , V_37 ) ;
F_36 ( V_2 , & V_17 ) ;
F_29 ( V_29 , V_31 , 0 , V_17 , V_39 ) ;
F_37 ( V_29 , V_35 , 127 ) ;
V_28 = F_31 ( V_29 , V_2 -> V_30 -> V_36 , V_37 ) ;
if ( F_32 ( V_28 ) )
goto free;
F_17 ( V_29 ) ;
V_33:
return V_28 ;
free:
F_33 ( V_29 ) ;
goto V_33;
}
static int F_38 ( struct V_1 * V_2 )
{
T_1 V_37 [ V_38 ] , V_17 ;
int V_28 = 1 ;
T_2 V_40 ;
struct V_1 * V_29 ;
V_40 = F_39 ( F_40 ( V_2 ) -> V_41 ) - 3 ;
V_29 = F_28 ( NULL , V_2 -> V_30 , V_31 , V_40 ) ;
if ( ! V_29 )
goto V_33;
V_28 = 0 ;
F_35 ( V_2 , V_37 ) ;
F_36 ( V_2 , & V_17 ) ;
F_29 ( V_29 , V_31 , 0 , V_17 , V_39 ) ;
F_41 ( V_29 , V_2 ) ;
V_28 = F_31 ( V_29 , V_2 -> V_30 -> V_36 , V_37 ) ;
if ( F_32 ( V_28 ) )
goto free;
F_17 ( V_29 ) ;
V_33:
return V_28 ;
free:
F_33 ( V_29 ) ;
goto V_33;
}
static int F_42 ( struct V_1 * V_2 )
{
return 0 ;
}
static T_3 F_43 ( struct V_42 * V_43 ,
struct V_1 * V_2 )
{
T_3 V_28 = 0 ;
T_4 * V_44 = V_43 -> V_45 ;
for (; V_44 && * V_44 ; V_44 ++ )
if ( (* V_44)( V_2 ) )
V_28 = 1 ;
return V_28 ;
}
static struct V_42 *
F_44 ( struct V_1 * V_2 )
{
int V_46 = 0 ;
struct V_42 * V_28 = NULL ;
struct V_42 * * V_47 ;
struct V_48 * V_49 =
& V_50 [ V_10 . V_51 - 1 ] ;
for ( V_47 = V_49 -> V_52 ; V_47 [ V_46 ] -> V_4 ; V_46 ++ )
if ( ! V_47 [ V_46 ] -> V_4 ( V_2 ) ) {
V_28 = V_47 [ V_46 ] ;
break;
}
return V_28 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> type == V_15 )
F_33 ( V_2 ) ;
}
static T_3 F_46 ( struct V_1 * V_2 )
{
T_3 V_28 = 1 ;
struct V_42 * V_43 ;
if ( V_10 . V_51 > V_53 )
goto V_33;
V_43 = F_44 ( V_2 ) ;
if ( V_43 ) {
V_28 = F_43 ( V_43 , V_2 ) ;
if ( ! V_28 )
V_10 . V_51 = V_43 -> V_54 ;
} else
V_28 = 0 ;
V_33:
F_45 ( V_2 ) ;
return V_28 ;
}
static void F_47 ( void )
{
struct V_1 * V_2 ;
while ( ( V_2 = F_19 ( & V_10 . V_55 . V_56 ) ) != NULL )
F_46 ( V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_49 ( & V_10 . V_55 . V_57 ) ;
F_18 ( & V_10 . V_55 . V_56 , V_2 ) ;
F_47 () ;
F_50 ( & V_10 . V_55 . V_57 ) ;
}
static void F_51 ( unsigned long V_58 )
{
struct V_1 * V_2 = F_52 ( 0 , V_59 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> type = V_9 ;
F_48 ( V_2 ) ;
}
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> type = V_15 ;
V_4 -> V_60 = 0 ;
F_48 ( V_2 ) ;
}
void T_5 F_54 ( void )
{
F_55 ( & V_10 . V_24 ) ;
F_55 ( & V_10 . V_55 . V_56 ) ;
F_56 ( & V_10 . V_55 . V_57 ) ;
F_57 ( & V_10 . V_25 , F_51 ,
( unsigned long ) & V_10 ) ;
V_10 . V_25 . V_61 = V_26 +
V_27 ;
V_10 . V_12 = 1 ;
V_10 . V_51 = V_62 ;
F_58 ( F_53 ) ;
}
void F_59 ( void )
{
F_58 ( NULL ) ;
}
