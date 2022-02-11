static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
T_1 V_6 ;
F_2 ( V_7 ) ;
F_3 () ;
V_6 = F_4 () + V_8 ;
F_5 () ;
F_6 () ;
while ( ! F_7 () ) {
if ( F_8 ( V_9 ) && F_4 () > V_6 ) {
F_9 ( V_7 ) ;
F_10 () ;
break;
}
}
F_11 () ;
F_12 () ;
F_9 ( V_7 ) ;
return V_5 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
F_14 ( V_10 ) ;
return V_5 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
unsigned long V_11 = F_16 ( V_12 ) ;
unsigned long V_13 ;
if ( F_17 ( V_14 < V_15 ) )
return V_5 ;
V_13 = V_11 ;
V_13 &= ~ V_16 ;
F_18 ( V_12 , V_13 ) ;
F_14 ( V_17 ) ;
F_18 ( V_12 , V_11 ) ;
return V_5 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
F_20 ( V_18 [ V_5 ] . V_19 ,
V_18 [ V_5 ] . V_20 ) ;
return V_5 ;
}
static int F_21 ( unsigned int V_21 )
{
struct V_1 * V_2 = F_22 ( V_22 , V_21 ) ;
if ( V_2 && F_23 () ) {
F_24 () ;
F_25 ( V_2 ) ;
F_26 () ;
}
return 0 ;
}
static int F_27 ( unsigned int V_21 )
{
struct V_1 * V_2 = F_22 ( V_22 , V_21 ) ;
if ( V_2 && F_23 () ) {
F_24 () ;
F_28 ( V_2 ) ;
F_26 () ;
}
return 0 ;
}
static int F_29 ( void )
{
int V_23 ;
struct V_3 * V_4 = & V_24 ;
V_4 -> V_25 = 0 ;
for ( V_23 = 0 ; V_23 < V_26 ; ++ V_23 ) {
if ( V_27 [ V_23 ] . V_28 == NULL )
continue;
V_4 -> V_29 [ V_4 -> V_25 ] =
V_27 [ V_23 ] ;
V_4 -> V_25 += 1 ;
}
V_4 -> V_30 = (struct V_30 * ) V_31 ;
return 0 ;
}
static inline void F_30 ( int V_5 , const char * V_32 ,
unsigned int V_33 ,
int (* F_31)( struct V_1 * ,
struct V_3 * ,
int ) ,
unsigned int V_34 ,
unsigned int V_35 ,
T_1 V_36 , T_1 V_37 )
{
F_32 ( V_38 [ V_5 ] . V_32 , V_32 , V_39 ) ;
F_32 ( V_38 [ V_5 ] . V_40 , V_32 , V_39 ) ;
V_38 [ V_5 ] . V_33 = V_33 ;
V_38 [ V_5 ] . V_34 = V_34 ;
V_38 [ V_5 ] . V_35 = V_35 ;
V_38 [ V_5 ] . V_28 = F_31 ;
V_18 [ V_5 ] . V_19 = V_36 ;
V_18 [ V_5 ] . V_20 = V_37 ;
}
static inline int F_33 ( const char * V_41 , int V_42 ,
const char * V_43 , int V_44 )
{
if ( V_42 == V_44 )
return 0 ;
F_34 ( L_1 ,
V_41 , V_43 ) ;
return - 1 ;
}
static int F_35 ( void )
{
struct V_45 * V_46 ;
int V_47 = 1 ;
int V_48 , V_49 ;
T_2 V_50 [ V_51 ] ;
T_2 V_52 [ V_51 ] ;
T_2 V_33 [ V_51 ] ;
T_1 V_36 [ V_51 ] ;
T_1 V_37 [ V_51 ] ;
const char * V_53 [ V_51 ] ;
T_2 V_54 = 0 ;
int V_55 , V_56 ;
T_2 V_57 = F_36 () ;
V_46 = F_37 ( L_2 ) ;
if ( ! V_46 ) {
F_34 ( L_3 ) ;
goto V_58;
}
V_48 = F_38 ( V_46 , L_4 ) ;
if ( V_48 < 0 ) {
F_34 ( L_5 ) ;
goto V_58;
}
V_49 = F_38 ( V_46 ,
L_6 ) ;
if ( F_33 ( L_4 , V_48 ,
L_6 ,
V_49 ) != 0 )
goto V_58;
V_49 = F_39 ( V_46 ,
L_7 ) ;
if ( F_33 ( L_4 , V_48 ,
L_7 ,
V_49 ) != 0 )
goto V_58;
if ( V_48 > V_51 - 1 ) {
F_34 ( L_8 ) ;
V_48 = V_51 - 1 ;
}
if ( F_40 ( V_46 ,
L_4 , V_33 , V_48 ) ) {
F_34 ( L_9 ) ;
goto V_58;
}
if ( F_40 ( V_46 ,
L_6 , V_50 ,
V_48 ) ) {
F_34 ( L_10 ) ;
goto V_58;
}
if ( F_41 ( V_46 ,
L_7 , V_53 , V_48 ) < 0 ) {
F_34 ( L_11 ) ;
goto V_58;
}
V_54 = ( V_33 [ 0 ] &
( V_59 | V_60 ) ) ;
if ( V_54 ) {
V_49 = F_42 ( V_46 ,
L_12 ) ;
if ( F_33 ( L_4 ,
V_48 ,
L_12 ,
V_49 ) != 0 )
goto V_58;
V_49 = F_42 ( V_46 ,
L_13 ) ;
if ( F_33 ( L_4 ,
V_48 ,
L_13 ,
V_49 ) != 0 )
goto V_58;
if ( F_43 ( V_46 ,
L_12 , V_36 , V_48 ) ) {
F_34 ( L_14 ) ;
goto V_58;
}
if ( F_43 ( V_46 ,
L_13 ,
V_37 , V_48 ) ) {
F_34 ( L_15 ) ;
goto V_58;
}
}
V_49 = F_38 ( V_46 ,
L_16 ) ;
if ( V_49 < 0 ) {
V_56 = V_49 ;
} else if ( F_33 ( L_4 ,
V_48 ,
L_16 ,
V_49 ) != 0 ) {
goto V_58;
} else {
V_56 = F_40 ( V_46 ,
L_16 ,
V_52 , V_48 ) ;
}
for ( V_55 = 0 ; V_55 < V_48 ; V_55 ++ ) {
unsigned int V_35 , V_34 ;
bool V_61 = false ;
if ( ( V_33 [ V_55 ] & V_57 ) != V_33 [ V_55 ] )
continue;
if ( V_50 [ V_55 ] > V_62 )
continue;
V_35 = V_50 [ V_55 ] / 1000 ;
if ( ! V_56 )
V_34 = V_52 [ V_55 ] / 1000 ;
else
V_34 = 0 ;
if ( V_54 ) {
int V_63 = F_44 ( & V_36 [ V_55 ] ,
& V_37 [ V_55 ] ,
V_33 [ V_55 ] ) ;
if ( V_63 ) {
F_45 ( V_36 [ V_55 ] , V_63 ) ;
continue;
}
}
if ( V_33 [ V_55 ] & V_64 )
V_61 = true ;
if ( V_33 [ V_55 ] & V_65 ) {
if ( ! V_56 )
V_34 = 100 ;
F_30 ( V_47 , L_17 ,
V_66 , F_13 ,
V_34 , V_35 , 0 , 0 ) ;
} else if ( V_54 && ! V_61 ) {
F_30 ( V_47 , V_53 [ V_55 ] ,
V_66 , F_19 ,
V_34 , V_35 ,
V_36 [ V_55 ] , V_37 [ V_55 ] ) ;
}
#ifdef F_46
else if ( V_33 [ V_55 ] & V_67 ||
V_33 [ V_55 ] & V_68 ) {
if ( ! V_56 )
V_34 = 300000 ;
F_30 ( V_47 , L_18 ,
V_69 ,
F_15 ,
V_34 , V_35 , 0 , 0 ) ;
} else if ( V_54 && V_61 ) {
F_30 ( V_47 , V_53 [ V_55 ] ,
V_69 , F_19 ,
V_34 , V_35 ,
V_36 [ V_55 ] , V_37 [ V_55 ] ) ;
}
#endif
else
continue;
V_47 ++ ;
}
V_58:
return V_47 ;
}
static int F_47 ( void )
{
if ( V_70 != V_71 )
return - V_72 ;
if ( F_48 ( V_73 ) ) {
V_27 = V_38 ;
V_26 = F_35 () ;
if ( V_26 > 1 ) {
V_9 = true ;
V_8 = V_38 [ 1 ] . V_34 *
V_74 ;
}
} else
return - V_72 ;
return 0 ;
}
static int T_3 F_49 ( void )
{
int V_75 ;
V_75 = F_47 () ;
if ( V_75 )
return V_75 ;
F_29 () ;
V_75 = F_50 ( & V_24 , NULL ) ;
if ( V_75 ) {
F_51 ( V_76 L_19 ) ;
return V_75 ;
}
V_75 = F_52 ( V_77 ,
L_20 ,
F_21 , NULL ) ;
F_53 ( V_75 < 0 ) ;
V_75 = F_52 ( V_78 ,
L_21 , NULL ,
F_27 ) ;
F_53 ( V_75 < 0 ) ;
F_51 ( V_76 L_22 ) ;
return 0 ;
}
