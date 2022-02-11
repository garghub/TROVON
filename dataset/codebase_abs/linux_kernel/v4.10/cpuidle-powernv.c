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
static int F_22 ( unsigned int V_17 )
{
struct V_1 * V_2 = F_23 ( V_18 , V_17 ) ;
if ( V_2 && F_24 () ) {
F_25 () ;
F_26 ( V_2 ) ;
F_27 () ;
}
return 0 ;
}
static int F_28 ( unsigned int V_17 )
{
struct V_1 * V_2 = F_23 ( V_18 , V_17 ) ;
if ( V_2 && F_24 () ) {
F_25 () ;
F_29 ( V_2 ) ;
F_27 () ;
}
return 0 ;
}
static int F_30 ( void )
{
int V_19 ;
struct V_3 * V_4 = & V_20 ;
V_4 -> V_21 = 0 ;
for ( V_19 = 0 ; V_19 < V_22 ; ++ V_19 ) {
if ( V_23 [ V_19 ] . V_24 == NULL )
continue;
V_4 -> V_25 [ V_4 -> V_21 ] =
V_23 [ V_19 ] ;
V_4 -> V_21 += 1 ;
}
return 0 ;
}
static int F_31 ( void )
{
struct V_26 * V_27 ;
int V_28 = 1 ;
int V_29 ;
T_2 V_30 [ V_31 ] ;
T_2 V_32 [ V_31 ] ;
T_2 V_33 [ V_31 ] ;
T_1 V_34 [ V_31 ] ;
const char * V_35 [ V_31 ] ;
int V_36 , V_37 ;
V_27 = F_32 ( L_1 ) ;
if ( ! V_27 ) {
F_33 ( L_2 ) ;
goto V_38;
}
V_29 = F_34 ( V_27 , L_3 ) ;
if ( V_29 < 0 ) {
F_33 ( L_4 ) ;
goto V_38;
}
if ( V_29 > V_31 - 1 ) {
F_33 ( L_5 ) ;
V_29 = V_31 - 1 ;
}
if ( F_35 ( V_27 ,
L_3 , V_33 , V_29 ) ) {
F_33 ( L_6 ) ;
goto V_38;
}
if ( F_35 ( V_27 ,
L_7 , V_30 ,
V_29 ) ) {
F_33 ( L_8 ) ;
goto V_38;
}
if ( F_36 ( V_27 ,
L_9 , V_35 , V_29 ) < 0 ) {
F_33 ( L_10 ) ;
goto V_38;
}
if ( V_33 [ 0 ] & ( V_39 | V_40 ) )
if ( F_37 ( V_27 ,
L_11 , V_34 , V_29 ) ) {
F_33 ( L_12 ) ;
goto V_38;
}
V_37 = F_35 ( V_27 ,
L_13 , V_32 , V_29 ) ;
for ( V_36 = 0 ; V_36 < V_29 ; V_36 ++ ) {
if ( V_30 [ V_36 ] > V_41 )
continue;
if ( V_33 [ V_36 ] & V_42 ) {
strcpy ( V_43 [ V_28 ] . V_44 , L_14 ) ;
strcpy ( V_43 [ V_28 ] . V_45 , L_14 ) ;
V_43 [ V_28 ] . V_33 = 0 ;
V_43 [ V_28 ] . V_46 = 100 ;
V_43 [ V_28 ] . V_24 = F_13 ;
} else if ( ( V_33 [ V_36 ] & V_39 ) &&
! ( V_33 [ V_36 ] & V_47 ) ) {
strncpy ( V_43 [ V_28 ] . V_44 ,
V_35 [ V_36 ] , V_48 ) ;
strncpy ( V_43 [ V_28 ] . V_45 ,
V_35 [ V_36 ] , V_48 ) ;
V_43 [ V_28 ] . V_33 = 0 ;
V_43 [ V_28 ] . V_24 = F_20 ;
V_16 [ V_28 ] = V_34 [ V_36 ] ;
}
#ifdef F_38
if ( V_33 [ V_36 ] & V_49 ||
V_33 [ V_36 ] & V_50 ) {
strcpy ( V_43 [ V_28 ] . V_44 , L_15 ) ;
strcpy ( V_43 [ V_28 ] . V_45 , L_15 ) ;
V_43 [ V_28 ] . V_33 = V_51 ;
V_43 [ V_28 ] . V_46 = 300000 ;
V_43 [ V_28 ] . V_24 = F_15 ;
} else if ( ( V_33 [ V_36 ] & V_40 ) &&
( V_33 [ V_36 ] & V_47 ) ) {
strncpy ( V_43 [ V_28 ] . V_44 ,
V_35 [ V_36 ] , V_48 ) ;
strncpy ( V_43 [ V_28 ] . V_45 ,
V_35 [ V_36 ] , V_48 ) ;
V_43 [ V_28 ] . V_33 = V_51 ;
V_43 [ V_28 ] . V_24 = F_20 ;
V_16 [ V_28 ] = V_34 [ V_36 ] ;
}
#endif
V_43 [ V_28 ] . V_52 =
( ( unsigned int ) V_30 [ V_36 ] ) / 1000 ;
if ( ! V_37 ) {
V_43 [ V_28 ] . V_46 =
( ( unsigned int ) V_32 [ V_36 ] ) / 1000 ;
}
V_28 ++ ;
}
V_38:
return V_28 ;
}
static int F_39 ( void )
{
if ( V_53 != V_54 )
return - V_55 ;
if ( F_40 ( V_56 ) ) {
V_23 = V_43 ;
V_22 = F_31 () ;
if ( V_22 > 1 ) {
V_9 = true ;
V_8 = V_43 [ 1 ] . V_46 *
V_57 ;
}
} else
return - V_55 ;
return 0 ;
}
static int T_3 F_41 ( void )
{
int V_58 ;
V_58 = F_39 () ;
if ( V_58 )
return V_58 ;
F_30 () ;
V_58 = F_42 ( & V_20 , NULL ) ;
if ( V_58 ) {
F_43 ( V_59 L_16 ) ;
return V_58 ;
}
V_58 = F_44 ( V_60 ,
L_17 ,
F_22 , NULL ) ;
F_45 ( V_58 < 0 ) ;
V_58 = F_44 ( V_61 ,
L_18 , NULL ,
F_28 ) ;
F_45 ( V_58 < 0 ) ;
F_43 ( V_59 L_19 ) ;
return 0 ;
}
