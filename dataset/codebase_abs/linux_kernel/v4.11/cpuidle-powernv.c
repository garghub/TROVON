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
F_21 ( V_16 [ V_5 ] . V_17 ,
V_16 [ V_5 ] . V_18 ) ;
F_10 () ;
return V_5 ;
}
static int F_22 ( unsigned int V_19 )
{
struct V_1 * V_2 = F_23 ( V_20 , V_19 ) ;
if ( V_2 && F_24 () ) {
F_25 () ;
F_26 ( V_2 ) ;
F_27 () ;
}
return 0 ;
}
static int F_28 ( unsigned int V_19 )
{
struct V_1 * V_2 = F_23 ( V_20 , V_19 ) ;
if ( V_2 && F_24 () ) {
F_25 () ;
F_29 ( V_2 ) ;
F_27 () ;
}
return 0 ;
}
static int F_30 ( void )
{
int V_21 ;
struct V_3 * V_4 = & V_22 ;
V_4 -> V_23 = 0 ;
for ( V_21 = 0 ; V_21 < V_24 ; ++ V_21 ) {
if ( V_25 [ V_21 ] . V_26 == NULL )
continue;
V_4 -> V_27 [ V_4 -> V_23 ] =
V_25 [ V_21 ] ;
V_4 -> V_23 += 1 ;
}
V_4 -> V_28 = (struct V_28 * ) V_29 ;
return 0 ;
}
static inline void F_31 ( int V_5 , const char * V_30 ,
unsigned int V_31 ,
int (* F_32)( struct V_1 * ,
struct V_3 * ,
int ) ,
unsigned int V_32 ,
unsigned int V_33 ,
T_1 V_34 , T_1 V_35 )
{
F_33 ( V_36 [ V_5 ] . V_30 , V_30 , V_37 ) ;
F_33 ( V_36 [ V_5 ] . V_38 , V_30 , V_37 ) ;
V_36 [ V_5 ] . V_31 = V_31 ;
V_36 [ V_5 ] . V_32 = V_32 ;
V_36 [ V_5 ] . V_33 = V_33 ;
V_36 [ V_5 ] . V_26 = F_32 ;
V_16 [ V_5 ] . V_17 = V_34 ;
V_16 [ V_5 ] . V_18 = V_35 ;
}
static int F_34 ( void )
{
struct V_39 * V_40 ;
int V_41 = 1 ;
int V_42 ;
T_2 V_43 [ V_44 ] ;
T_2 V_45 [ V_44 ] ;
T_2 V_31 [ V_44 ] ;
T_1 V_34 [ V_44 ] ;
T_1 V_35 [ V_44 ] ;
const char * V_46 [ V_44 ] ;
T_2 V_47 = 0 ;
int V_48 , V_49 ;
V_40 = F_35 ( L_1 ) ;
if ( ! V_40 ) {
F_36 ( L_2 ) ;
goto V_50;
}
V_42 = F_37 ( V_40 , L_3 ) ;
if ( V_42 < 0 ) {
F_36 ( L_4 ) ;
goto V_50;
}
if ( V_42 > V_44 - 1 ) {
F_36 ( L_5 ) ;
V_42 = V_44 - 1 ;
}
if ( F_38 ( V_40 ,
L_3 , V_31 , V_42 ) ) {
F_36 ( L_6 ) ;
goto V_50;
}
if ( F_38 ( V_40 ,
L_7 , V_43 ,
V_42 ) ) {
F_36 ( L_8 ) ;
goto V_50;
}
if ( F_39 ( V_40 ,
L_9 , V_46 , V_42 ) < 0 ) {
F_36 ( L_10 ) ;
goto V_50;
}
V_47 = ( V_31 [ 0 ] &
( V_51 | V_52 ) ) ;
if ( V_47 ) {
if ( F_40 ( V_40 ,
L_11 , V_34 , V_42 ) ) {
F_36 ( L_12 ) ;
goto V_50;
}
if ( F_40 ( V_40 ,
L_13 ,
V_35 , V_42 ) ) {
F_36 ( L_14 ) ;
goto V_50;
}
}
V_49 = F_38 ( V_40 ,
L_15 , V_45 , V_42 ) ;
for ( V_48 = 0 ; V_48 < V_42 ; V_48 ++ ) {
unsigned int V_33 , V_32 ;
if ( V_43 [ V_48 ] > V_53 )
continue;
V_33 = V_43 [ V_48 ] / 1000 ;
if ( ! V_49 )
V_32 = V_45 [ V_48 ] / 1000 ;
else
V_32 = 0 ;
if ( V_47 ) {
int V_54 = F_41 ( & V_34 [ V_48 ] ,
& V_35 [ V_48 ] ,
V_31 [ V_48 ] ) ;
if ( V_54 ) {
F_42 ( V_34 [ V_48 ] , V_54 ) ;
continue;
}
}
if ( V_31 [ V_48 ] & V_55 ) {
if ( ! V_49 )
V_32 = 100 ;
F_31 ( V_41 , L_16 ,
V_56 , F_13 ,
V_32 , V_33 , 0 , 0 ) ;
} else if ( ( V_31 [ V_48 ] & V_51 ) &&
! ( V_31 [ V_48 ] & V_57 ) ) {
F_31 ( V_41 , V_46 [ V_48 ] ,
V_56 , F_20 ,
V_32 , V_33 ,
V_34 [ V_48 ] , V_35 [ V_48 ] ) ;
}
#ifdef F_43
if ( V_31 [ V_48 ] & V_58 ||
V_31 [ V_48 ] & V_59 ) {
if ( ! V_49 )
V_32 = 300000 ;
F_31 ( V_41 , L_17 ,
V_60 ,
F_15 ,
V_32 , V_33 , 0 , 0 ) ;
} else if ( ( V_31 [ V_48 ] & V_52 ) &&
( V_31 [ V_48 ] & V_57 ) ) {
F_31 ( V_41 , V_46 [ V_48 ] ,
V_60 , F_20 ,
V_32 , V_33 ,
V_34 [ V_48 ] , V_35 [ V_48 ] ) ;
}
#endif
V_41 ++ ;
}
V_50:
return V_41 ;
}
static int F_44 ( void )
{
if ( V_61 != V_62 )
return - V_63 ;
if ( F_45 ( V_64 ) ) {
V_25 = V_36 ;
V_24 = F_34 () ;
if ( V_24 > 1 ) {
V_9 = true ;
V_8 = V_36 [ 1 ] . V_32 *
V_65 ;
}
} else
return - V_63 ;
return 0 ;
}
static int T_3 F_46 ( void )
{
int V_66 ;
V_66 = F_44 () ;
if ( V_66 )
return V_66 ;
F_30 () ;
V_66 = F_47 ( & V_22 , NULL ) ;
if ( V_66 ) {
F_48 ( V_67 L_18 ) ;
return V_66 ;
}
V_66 = F_49 ( V_68 ,
L_19 ,
F_22 , NULL ) ;
F_50 ( V_66 < 0 ) ;
V_66 = F_49 ( V_69 ,
L_20 , NULL ,
F_28 ) ;
F_50 ( V_66 < 0 ) ;
F_48 ( V_67 L_21 ) ;
return 0 ;
}
