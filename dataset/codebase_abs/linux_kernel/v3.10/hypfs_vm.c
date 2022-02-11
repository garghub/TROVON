static int F_1 ( int V_1 , char * V_2 , void * V_3 )
{
unsigned long V_4 ;
unsigned long V_5 ;
struct V_6 V_7 ;
memcpy ( V_7 . V_8 , V_2 , V_9 ) ;
F_2 ( V_7 . V_8 , V_9 ) ;
V_7 . V_3 = ( unsigned long ) V_3 ;
V_7 . V_1 = V_1 ;
V_7 . V_10 = 0x02 ;
memset ( V_7 . V_11 , 0x40 , V_9 ) ;
V_5 = - 1 ;
asm volatile(
" diag %0,%1,0x2fc\n"
"0:\n"
EX_TABLE(0b,0b)
: "=d" (residual_cnt), "+d" (rc) : "0" (&parm_list) : "memory");
if ( ( V_5 != 0 ) && ( V_5 != - 2 ) )
return V_5 ;
else
return - V_4 ;
}
static void * F_3 ( char * V_2 , unsigned int * V_12 , int V_13 )
{
void * V_14 ;
int V_1 ;
do {
V_1 = F_1 ( 0 , V_2 , NULL ) ;
if ( V_1 < 0 )
return F_4 ( - V_15 ) ;
V_14 = F_5 ( V_1 + V_13 ) ;
if ( ! V_14 )
return F_4 ( - V_16 ) ;
if ( F_1 ( V_1 , V_2 , V_14 + V_13 ) == 0 )
break;
F_6 ( V_14 ) ;
} while ( 1 );
* V_12 = ( V_1 / sizeof( struct V_17 ) ) ;
return V_14 ;
}
static void F_7 ( const void * V_14 )
{
F_6 ( V_14 ) ;
}
static int F_8 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_17 * V_14 )
{
char V_22 [ V_9 + 1 ] = {} ;
struct V_20 * V_23 , * V_24 , * V_25 , * V_26 ;
int V_27 , V_28 ;
V_28 = ( V_14 -> V_29 & 0x00000006 ) >> 1 ;
V_27 = ( V_14 -> V_29 & 0x00000008 ) >> 3 ;
memcpy ( V_22 , V_14 -> V_22 , V_9 ) ;
F_9 ( V_22 , V_9 ) ;
F_10 ( V_22 ) ;
V_23 = F_11 ( V_19 , V_21 , V_22 ) ;
if ( F_12 ( V_23 ) )
return F_13 ( V_23 ) ;
F_14 ( V_19 , V_23 , L_1 , V_14 -> V_30 ) ;
V_24 = F_11 ( V_19 , V_23 , L_2 ) ;
if ( F_12 ( V_24 ) )
return F_13 ( V_24 ) ;
F_14 ( V_19 , V_24 , L_3 , V_14 -> V_31 ) ;
F_14 ( V_19 , V_24 , L_4 , V_28 ) ;
F_14 ( V_19 , V_24 , L_5 , V_27 ) ;
F_14 ( V_19 , V_24 , L_6 , V_14 -> V_32 ) ;
F_14 ( V_19 , V_24 , L_7 , V_14 -> V_33 ) ;
F_14 ( V_19 , V_24 , L_8 , V_14 -> V_34 ) ;
F_14 ( V_19 , V_24 , L_9 , V_14 -> V_35 ) ;
V_26 = F_11 ( V_19 , V_23 , L_10 ) ;
if ( F_12 ( V_26 ) )
return F_13 ( V_26 ) ;
F_14 ( V_19 , V_26 , L_11 , V_14 -> V_36 ) ;
F_14 ( V_19 , V_26 , L_12 , V_14 -> V_37 ) ;
F_14 ( V_19 , V_26 , L_13 , V_14 -> V_38 ) ;
F_14 ( V_19 , V_26 , L_14 , V_14 -> V_39 ) ;
V_25 = F_11 ( V_19 , V_23 , L_15 ) ;
if ( F_12 ( V_25 ) )
return F_13 ( V_25 ) ;
F_14 ( V_19 , V_25 , L_16 , V_14 -> V_40 ) ;
F_14 ( V_19 , V_25 , L_17 , V_14 -> V_41 ) ;
F_14 ( V_19 , V_25 , L_18 , V_14 -> V_42 ) ;
F_14 ( V_19 , V_25 , L_19 , V_14 -> V_43 ) ;
F_14 ( V_19 , V_25 , L_20 , V_14 -> V_44 ) ;
F_14 ( V_19 , V_25 , L_21 , V_14 -> V_45 ) ;
return 0 ;
}
int F_15 ( struct V_18 * V_19 , struct V_20 * V_46 )
{
struct V_20 * V_47 , * V_48 ;
struct V_17 * V_14 ;
unsigned int V_12 = 0 ;
int V_5 , V_49 ;
V_14 = F_3 ( V_50 , & V_12 , 0 ) ;
if ( F_12 ( V_14 ) )
return F_13 ( V_14 ) ;
V_47 = F_11 ( V_19 , V_46 , L_22 ) ;
if ( F_12 ( V_47 ) ) {
V_5 = F_13 ( V_47 ) ;
goto V_51;
}
V_48 = F_16 ( V_19 , V_47 , L_23 , L_24 ) ;
if ( F_12 ( V_48 ) ) {
V_5 = F_13 ( V_48 ) ;
goto V_51;
}
V_47 = F_11 ( V_19 , V_46 , L_2 ) ;
if ( F_12 ( V_47 ) ) {
V_5 = F_13 ( V_47 ) ;
goto V_51;
}
V_48 = F_17 ( V_19 , V_47 , L_6 , V_14 -> V_52 ) ;
if ( F_12 ( V_48 ) ) {
V_5 = F_13 ( V_48 ) ;
goto V_51;
}
V_47 = F_11 ( V_19 , V_46 , L_25 ) ;
if ( F_12 ( V_47 ) ) {
V_5 = F_13 ( V_47 ) ;
goto V_51;
}
for ( V_49 = 0 ; V_49 < V_12 ; V_49 ++ ) {
V_5 = F_8 ( V_19 , V_47 , & ( V_14 [ V_49 ] ) ) ;
if ( V_5 )
goto V_51;
}
F_7 ( V_14 ) ;
return 0 ;
V_51:
F_7 ( V_14 ) ;
return V_5 ;
}
static int F_18 ( void * * V_14 , void * * V_53 , T_1 * V_1 )
{
struct V_54 * V_55 ;
unsigned int V_12 ;
V_55 = F_3 ( V_50 , & V_12 , sizeof( V_55 -> V_56 ) ) ;
if ( F_12 ( V_55 ) )
return F_13 ( V_55 ) ;
F_19 ( V_55 -> V_56 . V_57 ) ;
V_55 -> V_56 . V_58 = V_12 * sizeof( struct V_17 ) ;
V_55 -> V_56 . V_59 = V_60 ;
V_55 -> V_56 . V_12 = V_12 ;
memset ( & V_55 -> V_56 . V_61 , 0 , sizeof( V_55 -> V_56 . V_61 ) ) ;
* V_14 = V_55 ;
* V_53 = V_55 ;
* V_1 = V_55 -> V_56 . V_58 + sizeof( struct V_62 ) ;
return 0 ;
}
int F_20 ( void )
{
if ( ! V_63 )
return 0 ;
if ( F_1 ( 0 , V_64 , NULL ) > 0 )
V_50 = V_64 ;
else if ( F_1 ( 0 , V_65 , NULL ) > 0 )
V_50 = V_65 ;
else
return - V_15 ;
return F_21 ( & V_66 ) ;
}
void F_22 ( void )
{
if ( ! V_63 )
return;
F_23 ( & V_66 ) ;
}
