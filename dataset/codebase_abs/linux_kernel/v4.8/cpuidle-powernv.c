static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
T_1 V_6 ;
F_2 () ;
F_3 ( V_7 ) ;
V_6 = F_4 () + V_8 ;
F_5 () ;
while ( ! F_6 () ) {
F_7 () ;
F_8 () ;
if ( V_9 && F_4 () > V_6 )
break;
}
F_9 () ;
F_10 () ;
F_11 ( V_7 ) ;
F_12 () ;
return V_5 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
F_5 () ;
F_14 () ;
F_10 () ;
return V_5 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
unsigned long V_10 = F_16 ( V_11 ) ;
unsigned long V_12 ;
if ( F_17 ( V_13 < V_14 ) )
return V_5 ;
V_12 = V_10 ;
V_12 &= ~ V_15 ;
F_18 ( V_11 , V_12 ) ;
F_19 () ;
F_18 ( V_11 , V_10 ) ;
return V_5 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
F_5 () ;
F_21 ( V_16 [ V_5 ] ) ;
F_10 () ;
return V_5 ;
}
static int F_22 ( struct V_17 * V_18 ,
unsigned long V_19 , void * V_20 )
{
int V_21 = ( unsigned long ) V_20 ;
struct V_1 * V_2 =
F_23 ( V_22 , V_21 ) ;
if ( V_2 && F_24 () ) {
switch ( V_19 ) {
case V_23 :
case V_24 :
F_25 () ;
F_26 ( V_2 ) ;
F_27 () ;
break;
case V_25 :
case V_26 :
F_25 () ;
F_28 ( V_2 ) ;
F_27 () ;
break;
default:
return V_27 ;
}
}
return V_28 ;
}
static int F_29 ( void )
{
int V_29 ;
struct V_3 * V_4 = & V_30 ;
V_4 -> V_31 = 0 ;
for ( V_29 = 0 ; V_29 < V_32 ; ++ V_29 ) {
if ( V_33 [ V_29 ] . V_34 == NULL )
continue;
V_4 -> V_35 [ V_4 -> V_31 ] =
V_33 [ V_29 ] ;
V_4 -> V_31 += 1 ;
}
return 0 ;
}
static int F_30 ( void )
{
struct V_36 * V_37 ;
int V_38 = 1 ;
int V_39 ;
T_2 V_40 [ V_41 ] ;
T_2 V_42 [ V_41 ] ;
T_2 V_43 [ V_41 ] ;
T_1 V_44 [ V_41 ] ;
const char * V_45 [ V_41 ] ;
int V_46 , V_47 ;
V_37 = F_31 ( L_1 ) ;
if ( ! V_37 ) {
F_32 ( L_2 ) ;
goto V_48;
}
V_39 = F_33 ( V_37 , L_3 ) ;
if ( V_39 < 0 ) {
F_32 ( L_4 ) ;
goto V_48;
}
if ( V_39 > V_41 - 1 ) {
F_32 ( L_5 ) ;
V_39 = V_41 - 1 ;
}
if ( F_34 ( V_37 ,
L_3 , V_43 , V_39 ) ) {
F_32 ( L_6 ) ;
goto V_48;
}
if ( F_34 ( V_37 ,
L_7 , V_40 ,
V_39 ) ) {
F_32 ( L_8 ) ;
goto V_48;
}
if ( F_35 ( V_37 ,
L_9 , V_45 , V_39 ) < 0 ) {
F_32 ( L_10 ) ;
goto V_48;
}
if ( V_43 [ 0 ] & ( V_49 | V_50 ) )
if ( F_36 ( V_37 ,
L_11 , V_44 , V_39 ) ) {
F_32 ( L_12 ) ;
goto V_48;
}
V_47 = F_34 ( V_37 ,
L_13 , V_42 , V_39 ) ;
for ( V_46 = 0 ; V_46 < V_39 ; V_46 ++ ) {
if ( V_40 [ V_46 ] > V_51 )
continue;
if ( V_43 [ V_46 ] & V_52 ) {
strcpy ( V_53 [ V_38 ] . V_54 , L_14 ) ;
strcpy ( V_53 [ V_38 ] . V_55 , L_14 ) ;
V_53 [ V_38 ] . V_43 = 0 ;
V_53 [ V_38 ] . V_56 = 100 ;
V_53 [ V_38 ] . V_34 = F_13 ;
} else if ( ( V_43 [ V_46 ] & V_49 ) &&
! ( V_43 [ V_46 ] & V_57 ) ) {
strncpy ( V_53 [ V_38 ] . V_54 ,
V_45 [ V_46 ] , V_58 ) ;
strncpy ( V_53 [ V_38 ] . V_55 ,
V_45 [ V_46 ] , V_58 ) ;
V_53 [ V_38 ] . V_43 = 0 ;
V_53 [ V_38 ] . V_34 = F_20 ;
V_16 [ V_38 ] = V_44 [ V_46 ] ;
}
#ifdef F_37
if ( V_43 [ V_46 ] & V_59 ||
V_43 [ V_46 ] & V_60 ) {
strcpy ( V_53 [ V_38 ] . V_54 , L_15 ) ;
strcpy ( V_53 [ V_38 ] . V_55 , L_15 ) ;
V_53 [ V_38 ] . V_43 = V_61 ;
V_53 [ V_38 ] . V_56 = 300000 ;
V_53 [ V_38 ] . V_34 = F_15 ;
} else if ( ( V_43 [ V_46 ] & V_50 ) &&
( V_43 [ V_46 ] & V_57 ) ) {
strncpy ( V_53 [ V_38 ] . V_54 ,
V_45 [ V_46 ] , V_58 ) ;
strncpy ( V_53 [ V_38 ] . V_55 ,
V_45 [ V_46 ] , V_58 ) ;
V_53 [ V_38 ] . V_43 = V_61 ;
V_53 [ V_38 ] . V_34 = F_20 ;
V_16 [ V_38 ] = V_44 [ V_46 ] ;
}
#endif
V_53 [ V_38 ] . V_62 =
( ( unsigned int ) V_40 [ V_46 ] ) / 1000 ;
if ( ! V_47 ) {
V_53 [ V_38 ] . V_56 =
( ( unsigned int ) V_42 [ V_46 ] ) / 1000 ;
}
V_38 ++ ;
}
V_48:
return V_38 ;
}
static int F_38 ( void )
{
if ( V_63 != V_64 )
return - V_65 ;
if ( F_39 ( V_66 ) ) {
V_33 = V_53 ;
V_32 = F_30 () ;
if ( V_32 > 1 ) {
V_9 = true ;
V_8 = V_53 [ 1 ] . V_56 *
V_67 ;
}
} else
return - V_65 ;
return 0 ;
}
static int T_3 F_40 ( void )
{
int V_68 ;
V_68 = F_38 () ;
if ( V_68 )
return V_68 ;
F_29 () ;
V_68 = F_41 ( & V_30 , NULL ) ;
if ( V_68 ) {
F_42 ( V_69 L_16 ) ;
return V_68 ;
}
F_43 ( & V_70 ) ;
F_42 ( V_69 L_17 ) ;
return 0 ;
}
