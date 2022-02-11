void F_1 ( unsigned long V_1 , unsigned int V_2 )
{
unsigned long * V_3 = ( unsigned long * ) V_1 ;
for ( V_2 >>= 5 ; V_2 -- ; V_3 += 8 )
F_2 ( V_3 ) ;
F_3 () ;
}
static inline void F_4 ( struct V_4 * V_5 )
{
struct V_4 * * V_6 , * V_7 ;
F_5 ( & V_8 ) ;
V_6 = & V_9 ;
while ( ( V_7 = * V_6 ) != NULL )
V_6 = & V_7 -> V_10 ;
V_5 -> V_10 = V_7 ;
* V_6 = V_5 ;
F_6 ( & V_8 ) ;
}
static inline void F_7 ( struct V_4 * V_5 )
{
struct V_4 * * V_6 , * V_7 ;
F_5 ( & V_8 ) ;
for ( V_6 = & V_9 ; ( V_7 = * V_6 ) ; V_6 = & V_7 -> V_10 )
if ( V_7 == V_5 ) {
* V_6 = V_7 -> V_10 ;
break;
}
F_6 ( & V_8 ) ;
}
static int F_8 ( struct V_4 * V_5 , T_1 V_11 )
{
#if F_9 ( V_12 )
struct V_13 * V_14 ;
V_14 = F_10 ( V_5 -> V_15 , V_16 , V_5 -> V_17 , V_18 ) ;
if ( ! V_14 )
return - V_19 ;
V_14 -> V_20 = V_5 -> V_21 ;
if ( F_11 ( ( unsigned long ) V_14 -> V_21 ,
( unsigned long ) V_14 -> V_21 + V_5 -> V_15 ,
V_14 -> V_20 , V_11 ) ) {
F_12 ( V_14 -> V_21 ) ;
return - V_22 ;
}
#else
F_13 ( ( ( V_5 -> V_21 >> 26 ) << 2 ) & 0x1c , V_23 ) ;
F_13 ( ( ( V_5 -> V_21 >> 26 ) << 2 ) & 0x1c , V_24 ) ;
#endif
return 0 ;
}
unsigned long F_14 ( unsigned long V_25 , unsigned int V_15 ,
const char * V_26 , T_1 V_11 )
{
struct V_4 * V_5 ;
unsigned long V_27 ;
unsigned int V_28 ;
int V_29 , V_30 ;
V_27 = V_25 + V_15 - 1 ;
if ( F_15 ( ! V_15 || V_27 < V_25 ) )
return - V_31 ;
if ( F_15 ( V_25 < F_16 ( V_32 ) ) )
return - V_31 ;
V_25 &= V_33 ;
V_15 = F_17 ( V_27 + 1 ) - V_25 ;
V_5 = F_18 ( V_34 , V_35 ) ;
if ( F_15 ( ! V_5 ) )
return - V_19 ;
V_5 -> V_21 = V_25 ;
V_5 -> V_15 = V_15 ;
V_5 -> V_26 = V_26 ;
V_30 = F_19 ( V_36 , 0x04000000 >> V_37 ,
F_20 ( V_5 -> V_15 ) ) ;
if ( F_15 ( V_30 < 0 ) ) {
V_29 = - V_38 ;
goto V_39;
}
V_5 -> V_17 = V_40 + ( V_30 << V_37 ) ;
V_29 = F_8 ( V_5 , V_11 ) ;
if ( F_15 ( V_29 != 0 ) )
goto V_39;
V_28 = ( V_15 + ( V_41 - 1 ) ) >> V_37 ;
F_21 ( L_1 ,
F_22 ( V_5 -> V_26 ) ? V_5 -> V_26 : L_2 ,
V_28 , V_28 == 1 ? L_3 : L_4 ,
V_5 -> V_17 , V_5 -> V_21 ) ;
F_4 ( V_5 ) ;
return V_5 -> V_17 ;
V_39:
F_23 ( V_34 , V_5 ) ;
return V_29 ;
}
void F_24 ( unsigned long V_42 )
{
struct V_4 * * V_6 , * V_5 ;
int V_30 ;
for ( V_6 = & V_9 ; ( V_5 = * V_6 ) ; V_6 = & V_5 -> V_10 )
if ( V_5 -> V_17 == V_42 )
break;
if ( F_15 ( ! V_5 ) ) {
F_25 ( L_5 ,
V_43 , V_42 ) ;
return;
}
V_30 = ( V_5 -> V_17 - V_40 ) >> V_37 ;
F_26 ( V_36 , V_30 , F_20 ( V_5 -> V_15 ) ) ;
#ifdef V_12
{
struct V_13 * V_14 ;
V_14 = F_27 ( ( void * ) ( V_5 -> V_17 & V_33 ) ) ;
if ( ! V_14 ) {
F_25 ( V_44 L_6 ,
V_43 , V_5 -> V_17 ) ;
return;
}
}
#endif
F_7 ( V_5 ) ;
F_23 ( V_34 , V_5 ) ;
}
static T_2 F_28 ( struct V_45 * V_46 , struct V_47 * V_48 ,
char * V_49 )
{
struct V_50 * V_51 = F_29 ( V_48 ) ;
if ( F_22 ( V_51 -> V_52 ) )
return V_51 -> V_52 ( V_49 ) ;
return - V_53 ;
}
static T_2 F_30 ( struct V_45 * V_46 , struct V_47 * V_48 ,
const char * V_49 , T_3 V_54 )
{
struct V_50 * V_51 = F_29 ( V_48 ) ;
if ( F_22 ( V_51 -> V_55 ) )
return V_51 -> V_55 ( V_49 , V_54 ) ;
return - V_53 ;
}
static T_2 F_31 ( char * V_49 )
{
struct V_4 * * V_56 , * V_57 ;
char * V_6 = V_49 ;
for ( V_56 = & V_9 ; ( V_57 = * V_56 ) ; V_56 = & V_57 -> V_10 )
V_6 += sprintf ( V_6 , L_7 ,
V_57 -> V_17 , V_57 -> V_17 + V_57 -> V_15 ,
V_57 -> V_21 , V_57 -> V_26 ) ;
return V_6 - V_49 ;
}
static T_2 F_32 ( const char * V_49 , T_3 V_54 )
{
unsigned long V_58 = 0 , V_2 = 0 ;
sscanf ( V_49 , L_8 , & V_58 , & V_2 ) ;
if ( ! V_58 )
return - V_53 ;
if ( F_22 ( V_2 ) ) {
int V_29 = F_14 ( V_58 , V_2 , L_9 , V_59 ) ;
if ( V_29 < 0 )
return V_29 ;
} else
F_24 ( V_58 ) ;
return V_54 ;
}
static int F_33 ( struct V_60 * V_61 , struct V_62 * V_63 )
{
unsigned int V_64 = V_61 -> V_65 ;
struct V_45 * V_46 ;
int error ;
V_66 [ V_64 ] = F_34 ( sizeof( struct V_45 ) , V_35 ) ;
if ( F_15 ( ! V_66 [ V_64 ] ) )
return - V_19 ;
V_46 = V_66 [ V_64 ] ;
error = F_35 ( V_46 , & V_67 , & V_61 -> V_46 ,
L_10 , L_11 ) ;
if ( ! error )
F_36 ( V_46 , V_68 ) ;
return error ;
}
static void F_37 ( struct V_60 * V_61 , struct V_62 * V_63 )
{
unsigned int V_64 = V_61 -> V_65 ;
struct V_45 * V_46 = V_66 [ V_64 ] ;
F_38 ( V_46 ) ;
}
static int T_4 F_39 ( void )
{
unsigned int V_69 = 0x04000000 >> V_37 ;
unsigned int V_15 = ( V_69 + ( V_70 - 1 ) ) / V_70 ;
int V_29 = - V_19 ;
F_25 ( V_71 L_12 ) ;
V_34 = F_40 ( L_13 ,
sizeof( struct V_4 ) , 0 , 0 , NULL ) ;
if ( F_15 ( ! V_34 ) )
return V_29 ;
V_36 = F_34 ( V_15 , V_35 ) ;
if ( F_15 ( ! V_36 ) )
goto V_39;
V_29 = F_41 ( & V_72 ) ;
if ( F_15 ( V_29 != 0 ) )
goto V_39;
return 0 ;
V_39:
F_42 ( V_36 ) ;
F_43 ( V_34 ) ;
return V_29 ;
}
static void T_5 F_44 ( void )
{
F_45 ( & V_72 ) ;
F_42 ( V_36 ) ;
F_43 ( V_34 ) ;
}
