static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
T_1 V_6 ;
F_2 () ;
F_3 ( V_7 ) ;
V_6 = F_4 () + V_8 ;
F_5 () ;
F_6 () ;
while ( ! F_7 () ) {
if ( F_8 ( V_9 ) && F_4 () > V_6 )
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
static inline int F_34 ( const char * V_39 , int V_40 ,
const char * V_41 , int V_42 )
{
if ( V_40 == V_42 )
return 0 ;
F_35 ( L_1 ,
V_39 , V_41 ) ;
return - 1 ;
}
static int F_36 ( void )
{
struct V_43 * V_44 ;
int V_45 = 1 ;
int V_46 , V_47 ;
T_2 V_48 [ V_49 ] ;
T_2 V_50 [ V_49 ] ;
T_2 V_31 [ V_49 ] ;
T_1 V_34 [ V_49 ] ;
T_1 V_35 [ V_49 ] ;
const char * V_51 [ V_49 ] ;
T_2 V_52 = 0 ;
int V_53 , V_54 ;
V_44 = F_37 ( L_2 ) ;
if ( ! V_44 ) {
F_35 ( L_3 ) ;
goto V_55;
}
V_46 = F_38 ( V_44 , L_4 ) ;
if ( V_46 < 0 ) {
F_35 ( L_5 ) ;
goto V_55;
}
V_47 = F_38 ( V_44 ,
L_6 ) ;
if ( F_34 ( L_4 , V_46 ,
L_6 ,
V_47 ) != 0 )
goto V_55;
V_47 = F_39 ( V_44 ,
L_7 ) ;
if ( F_34 ( L_4 , V_46 ,
L_7 ,
V_47 ) != 0 )
goto V_55;
if ( V_46 > V_49 - 1 ) {
F_35 ( L_8 ) ;
V_46 = V_49 - 1 ;
}
if ( F_40 ( V_44 ,
L_4 , V_31 , V_46 ) ) {
F_35 ( L_9 ) ;
goto V_55;
}
if ( F_40 ( V_44 ,
L_6 , V_48 ,
V_46 ) ) {
F_35 ( L_10 ) ;
goto V_55;
}
if ( F_41 ( V_44 ,
L_7 , V_51 , V_46 ) < 0 ) {
F_35 ( L_11 ) ;
goto V_55;
}
V_52 = ( V_31 [ 0 ] &
( V_56 | V_57 ) ) ;
if ( V_52 ) {
V_47 = F_42 ( V_44 ,
L_12 ) ;
if ( F_34 ( L_4 ,
V_46 ,
L_12 ,
V_47 ) != 0 )
goto V_55;
V_47 = F_42 ( V_44 ,
L_13 ) ;
if ( F_34 ( L_4 ,
V_46 ,
L_13 ,
V_47 ) != 0 )
goto V_55;
if ( F_43 ( V_44 ,
L_12 , V_34 , V_46 ) ) {
F_35 ( L_14 ) ;
goto V_55;
}
if ( F_43 ( V_44 ,
L_13 ,
V_35 , V_46 ) ) {
F_35 ( L_15 ) ;
goto V_55;
}
}
V_47 = F_38 ( V_44 ,
L_16 ) ;
if ( V_47 < 0 ) {
V_54 = V_47 ;
} else if ( F_34 ( L_4 ,
V_46 ,
L_16 ,
V_47 ) != 0 ) {
goto V_55;
} else {
V_54 = F_40 ( V_44 ,
L_16 ,
V_50 , V_46 ) ;
}
for ( V_53 = 0 ; V_53 < V_46 ; V_53 ++ ) {
unsigned int V_33 , V_32 ;
if ( V_48 [ V_53 ] > V_58 )
continue;
V_33 = V_48 [ V_53 ] / 1000 ;
if ( ! V_54 )
V_32 = V_50 [ V_53 ] / 1000 ;
else
V_32 = 0 ;
if ( V_52 ) {
int V_59 = F_44 ( & V_34 [ V_53 ] ,
& V_35 [ V_53 ] ,
V_31 [ V_53 ] ) ;
if ( V_59 ) {
F_45 ( V_34 [ V_53 ] , V_59 ) ;
continue;
}
}
if ( V_31 [ V_53 ] & V_60 ) {
if ( ! V_54 )
V_32 = 100 ;
F_31 ( V_45 , L_17 ,
V_61 , F_13 ,
V_32 , V_33 , 0 , 0 ) ;
} else if ( ( V_31 [ V_53 ] & V_56 ) &&
! ( V_31 [ V_53 ] & V_62 ) ) {
F_31 ( V_45 , V_51 [ V_53 ] ,
V_61 , F_20 ,
V_32 , V_33 ,
V_34 [ V_53 ] , V_35 [ V_53 ] ) ;
}
#ifdef F_46
if ( V_31 [ V_53 ] & V_63 ||
V_31 [ V_53 ] & V_64 ) {
if ( ! V_54 )
V_32 = 300000 ;
F_31 ( V_45 , L_18 ,
V_65 ,
F_15 ,
V_32 , V_33 , 0 , 0 ) ;
} else if ( ( V_31 [ V_53 ] & V_57 ) &&
( V_31 [ V_53 ] & V_62 ) ) {
F_31 ( V_45 , V_51 [ V_53 ] ,
V_65 , F_20 ,
V_32 , V_33 ,
V_34 [ V_53 ] , V_35 [ V_53 ] ) ;
}
#endif
V_45 ++ ;
}
V_55:
return V_45 ;
}
static int F_47 ( void )
{
if ( V_66 != V_67 )
return - V_68 ;
if ( F_48 ( V_69 ) ) {
V_25 = V_36 ;
V_24 = F_36 () ;
if ( V_24 > 1 ) {
V_9 = true ;
V_8 = V_36 [ 1 ] . V_32 *
V_70 ;
}
} else
return - V_68 ;
return 0 ;
}
static int T_3 F_49 ( void )
{
int V_71 ;
V_71 = F_47 () ;
if ( V_71 )
return V_71 ;
F_30 () ;
V_71 = F_50 ( & V_22 , NULL ) ;
if ( V_71 ) {
F_51 ( V_72 L_19 ) ;
return V_71 ;
}
V_71 = F_52 ( V_73 ,
L_20 ,
F_22 , NULL ) ;
F_53 ( V_71 < 0 ) ;
V_71 = F_52 ( V_74 ,
L_21 , NULL ,
F_28 ) ;
F_53 ( V_71 < 0 ) ;
F_51 ( V_72 L_22 ) ;
return 0 ;
}
