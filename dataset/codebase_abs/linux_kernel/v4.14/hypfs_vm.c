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
F_3 ( V_12 ) ;
asm volatile(
" diag %0,%1,0x2fc\n"
"0: nopr %%r7\n"
EX_TABLE(0b,0b)
: "=d" (residual_cnt), "+d" (rc) : "0" (&parm_list) : "memory");
if ( ( V_5 != 0 ) && ( V_5 != - 2 ) )
return V_5 ;
else
return - V_4 ;
}
static void * F_4 ( char * V_2 , unsigned int * V_13 , int V_14 )
{
void * V_15 ;
int V_1 ;
do {
V_1 = F_1 ( 0 , V_2 , NULL ) ;
if ( V_1 < 0 )
return F_5 ( - V_16 ) ;
V_15 = F_6 ( V_1 + V_14 ) ;
if ( ! V_15 )
return F_5 ( - V_17 ) ;
if ( F_1 ( V_1 , V_2 , V_15 + V_14 ) == 0 )
break;
F_7 ( V_15 ) ;
} while ( 1 );
* V_13 = ( V_1 / sizeof( struct V_18 ) ) ;
return V_15 ;
}
static void F_8 ( const void * V_15 )
{
F_7 ( V_15 ) ;
}
static int F_9 ( struct V_19 * V_20 ,
struct V_18 * V_15 )
{
char V_21 [ V_9 + 1 ] = {} ;
struct V_19 * V_22 , * V_23 , * V_24 , * V_25 ;
int V_26 , V_27 ;
V_27 = ( V_15 -> V_28 & 0x00000006 ) >> 1 ;
V_26 = ( V_15 -> V_28 & 0x00000008 ) >> 3 ;
memcpy ( V_21 , V_15 -> V_21 , V_9 ) ;
F_10 ( V_21 , V_9 ) ;
F_11 ( V_21 ) ;
V_22 = F_12 ( V_20 , V_21 ) ;
if ( F_13 ( V_22 ) )
return F_14 ( V_22 ) ;
F_15 ( V_22 , L_1 , V_15 -> V_29 ) ;
V_23 = F_12 ( V_22 , L_2 ) ;
if ( F_13 ( V_23 ) )
return F_14 ( V_23 ) ;
F_15 ( V_23 , L_3 , V_15 -> V_30 ) ;
F_15 ( V_23 , L_4 , V_27 ) ;
F_15 ( V_23 , L_5 , V_26 ) ;
F_15 ( V_23 , L_6 , V_15 -> V_31 ) ;
F_15 ( V_23 , L_7 , V_15 -> V_32 ) ;
F_15 ( V_23 , L_8 , V_15 -> V_33 ) ;
F_15 ( V_23 , L_9 , V_15 -> V_34 ) ;
V_25 = F_12 ( V_22 , L_10 ) ;
if ( F_13 ( V_25 ) )
return F_14 ( V_25 ) ;
F_15 ( V_25 , L_11 , V_15 -> V_35 ) ;
F_15 ( V_25 , L_12 , V_15 -> V_36 ) ;
F_15 ( V_25 , L_13 , V_15 -> V_37 ) ;
F_15 ( V_25 , L_14 , V_15 -> V_38 ) ;
V_24 = F_12 ( V_22 , L_15 ) ;
if ( F_13 ( V_24 ) )
return F_14 ( V_24 ) ;
F_15 ( V_24 , L_16 , V_15 -> V_39 ) ;
F_15 ( V_24 , L_17 , V_15 -> V_40 ) ;
F_15 ( V_24 , L_18 , V_15 -> V_41 ) ;
F_15 ( V_24 , L_19 , V_15 -> V_42 ) ;
F_15 ( V_24 , L_20 , V_15 -> V_43 ) ;
F_15 ( V_24 , L_21 , V_15 -> V_44 ) ;
return 0 ;
}
int F_16 ( struct V_19 * V_45 )
{
struct V_19 * V_46 , * V_47 ;
struct V_18 * V_15 ;
unsigned int V_13 = 0 ;
int V_5 , V_48 ;
V_15 = F_4 ( V_49 , & V_13 , 0 ) ;
if ( F_13 ( V_15 ) )
return F_14 ( V_15 ) ;
V_46 = F_12 ( V_45 , L_22 ) ;
if ( F_13 ( V_46 ) ) {
V_5 = F_14 ( V_46 ) ;
goto V_50;
}
V_47 = F_17 ( V_46 , L_23 , L_24 ) ;
if ( F_13 ( V_47 ) ) {
V_5 = F_14 ( V_47 ) ;
goto V_50;
}
V_46 = F_12 ( V_45 , L_2 ) ;
if ( F_13 ( V_46 ) ) {
V_5 = F_14 ( V_46 ) ;
goto V_50;
}
V_47 = F_18 ( V_46 , L_6 , V_15 -> V_51 ) ;
if ( F_13 ( V_47 ) ) {
V_5 = F_14 ( V_47 ) ;
goto V_50;
}
V_46 = F_12 ( V_45 , L_25 ) ;
if ( F_13 ( V_46 ) ) {
V_5 = F_14 ( V_46 ) ;
goto V_50;
}
for ( V_48 = 0 ; V_48 < V_13 ; V_48 ++ ) {
V_5 = F_9 ( V_46 , & ( V_15 [ V_48 ] ) ) ;
if ( V_5 )
goto V_50;
}
F_8 ( V_15 ) ;
return 0 ;
V_50:
F_8 ( V_15 ) ;
return V_5 ;
}
static int F_19 ( void * * V_15 , void * * V_52 , T_1 * V_1 )
{
struct V_53 * V_54 ;
unsigned int V_13 ;
V_54 = F_4 ( V_49 , & V_13 , sizeof( V_54 -> V_55 ) ) ;
if ( F_13 ( V_54 ) )
return F_14 ( V_54 ) ;
F_20 ( V_54 -> V_55 . V_56 ) ;
V_54 -> V_55 . V_57 = V_13 * sizeof( struct V_18 ) ;
V_54 -> V_55 . V_58 = V_59 ;
V_54 -> V_55 . V_13 = V_13 ;
memset ( & V_54 -> V_55 . V_60 , 0 , sizeof( V_54 -> V_55 . V_60 ) ) ;
* V_15 = V_54 ;
* V_52 = V_54 ;
* V_1 = V_54 -> V_55 . V_57 + sizeof( struct V_61 ) ;
return 0 ;
}
int F_21 ( void )
{
if ( ! V_62 )
return 0 ;
if ( F_1 ( 0 , V_63 , NULL ) > 0 )
V_49 = V_63 ;
else if ( F_1 ( 0 , V_64 , NULL ) > 0 )
V_49 = V_64 ;
else
return - V_16 ;
return F_22 ( & V_65 ) ;
}
void F_23 ( void )
{
if ( ! V_62 )
return;
F_24 ( & V_65 ) ;
}
