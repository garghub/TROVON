static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_5 , T_1 V_6 , T_1 V_7 , T_1 V_8 ,
void * V_9 , T_2 V_10 ,
void * V_11 , T_2 V_12 )
{
unsigned long V_13 ;
T_1 V_14 ;
struct V_15 V_16 ;
int V_17 ;
if ( V_18 )
return V_19 ;
V_17 = F_2 () ;
V_16 = F_3 ( V_17 ) [ 0x40 / 8 ] ;
F_3 ( V_17 ) [ 0x40 / 8 ] = V_20 ;
F_4 ( & V_21 , V_13 ) ;
if ( V_10 )
F_5 ( F_6 () , V_22 , V_9 , V_10 ) ;
if ( V_12 )
F_5 ( F_6 () , V_23 , V_11 , V_12 ) ;
__asm__ __volatile__("pushl %%ebp\n\t"
"pushl %%edi\n\t"
"pushl %%esi\n\t"
"pushl %%ds\n\t"
"pushl %%es\n\t"
"pushl %%fs\n\t"
"pushl %%gs\n\t"
"pushfl\n\t"
"movl %%esp, pnp_bios_fault_esp\n\t"
"movl $1f, pnp_bios_fault_eip\n\t"
"lcall %5,%6\n\t"
"1:popfl\n\t"
"popl %%gs\n\t"
"popl %%fs\n\t"
"popl %%es\n\t"
"popl %%ds\n\t"
"popl %%esi\n\t"
"popl %%edi\n\t"
"popl %%ebp\n\t":"=a"(status)
:"0"((func) | (((u32) arg1) << 16)),
"b"((arg2) | (((u32) arg3) << 16)),
"c"((arg4) | (((u32) arg5) << 16)),
"d"((arg6) | (((u32) arg7) << 16)),
"i"(PNP_CS32), "i"(0)
:"memory");
F_7 ( & V_21 , V_13 ) ;
F_3 ( V_17 ) [ 0x40 / 8 ] = V_16 ;
F_8 () ;
if ( V_18 ) {
F_9 ( V_24
L_1 ) ;
F_9 ( V_24
L_2 ) ;
F_9 ( V_24
L_3 ) ;
}
return V_14 ;
}
void F_10 ( const char * V_25 , T_1 V_14 )
{
switch ( V_14 ) {
case V_26 :
F_9 ( V_24 L_4 , V_25 ) ;
break;
case V_27 :
F_9 ( V_24 L_5 ,
V_25 ) ;
break;
case V_28 :
F_9 ( V_24 L_6 ,
V_25 ) ;
break;
case V_19 :
F_9 ( V_24
L_7 ,
V_25 ) ;
break;
case V_29 :
F_9 ( V_24 L_8 , V_25 ) ;
break;
case V_30 :
F_9 ( V_24 L_9 ,
V_25 ) ;
break;
case V_31 :
F_9 ( V_24 L_10 ,
V_25 ) ;
break;
case V_32 :
F_9 ( V_24 L_11 , V_25 ) ;
break;
case V_33 :
F_9 ( V_24 L_12 ,
V_25 ) ;
break;
case V_34 :
F_9 ( V_24
L_13 ,
V_25 ) ;
break;
case V_35 :
F_9 ( V_24
L_14 ,
V_25 ) ;
break;
case V_36 :
F_9 ( V_24
L_15 ,
V_25 ) ;
break;
case V_37 :
F_9 ( V_24
L_16 ,
V_25 ) ;
break;
case V_38 :
F_9 ( V_24 L_17 ,
V_25 ) ;
break;
case V_39 :
F_9 ( V_24 L_18 , V_25 ) ;
break;
case V_40 :
F_9 ( V_24 L_19 ,
V_25 ) ;
break;
case V_41 :
F_9 ( V_24 L_20 ,
V_25 ) ;
break;
default:
F_9 ( V_24 L_21 , V_25 ,
V_14 ) ;
break;
}
}
static int F_11 ( struct V_42 * V_43 )
{
T_1 V_14 ;
if ( ! F_12 () )
return V_19 ;
V_14 = F_1 ( V_44 , 0 , V_22 , 2 ,
V_22 , V_45 , 0 , 0 , V_43 ,
sizeof( struct V_42 ) , NULL , 0 ) ;
V_43 -> V_46 &= 0xff ;
return V_14 ;
}
int F_13 ( struct V_42 * V_43 )
{
int V_14 = F_11 ( V_43 ) ;
if ( V_14 )
F_10 ( L_22 , V_14 ) ;
return V_14 ;
}
static int F_14 ( T_3 * V_47 , char V_48 ,
struct V_49 * V_43 )
{
T_1 V_14 ;
T_1 V_50 ;
if ( ! F_12 () )
return V_19 ;
if ( ! V_48 && V_51 )
return V_19 ;
V_50 = * V_47 ;
V_14 = F_1 ( V_52 , 0 , V_22 , 0 , V_23 ,
V_48 ? 2 : 1 , V_45 , 0 , & V_50 ,
sizeof( V_50 ) , V_43 , 65536 ) ;
* V_47 = V_50 ;
return V_14 ;
}
int F_15 ( T_3 * V_47 , char V_48 , struct V_49 * V_43 )
{
int V_14 ;
V_14 = F_14 ( V_47 , V_48 , V_43 ) ;
if ( V_14 )
F_10 ( L_23 , V_14 ) ;
return V_14 ;
}
static int F_16 ( T_3 V_47 , char V_48 ,
struct V_49 * V_43 )
{
T_1 V_14 ;
if ( ! F_12 () )
return V_19 ;
if ( ! V_48 && V_51 )
return V_19 ;
V_14 = F_1 ( V_53 , V_47 , 0 , V_22 ,
V_48 ? 2 : 1 , V_45 , 0 , 0 , V_43 , 65536 , NULL ,
0 ) ;
return V_14 ;
}
int F_17 ( T_3 V_47 , char V_48 , struct V_49 * V_43 )
{
int V_14 ;
V_14 = F_16 ( V_47 , V_48 , V_43 ) ;
if ( V_14 ) {
F_10 ( L_24 , V_14 ) ;
return V_14 ;
}
if ( ! V_48 ) {
V_14 = F_15 ( & V_47 , V_48 , V_43 ) ;
if ( V_14 )
return V_14 ;
}
return V_14 ;
}
int F_18 ( struct V_54 * V_43 )
{
T_1 V_14 ;
if ( ! F_12 () )
return V_19 ;
V_14 = F_1 ( V_55 , 0 , V_22 ,
V_45 , 0 , 0 , 0 , 0 , V_43 ,
sizeof( struct V_54 ) , NULL ,
0 ) ;
return V_14 ;
}
static int F_19 ( char * V_56 )
{
T_1 V_14 ;
if ( ! F_12 () )
return V_19 ;
V_14 = F_1 ( V_57 , 0 , V_22 ,
V_45 , 0 , 0 , 0 , 0 , V_56 , 65536 , NULL , 0 ) ;
return V_14 ;
}
int F_20 ( char * V_56 )
{
int V_14 ;
V_14 = F_19 ( V_56 ) ;
if ( V_14 )
F_10 ( L_25 , V_14 ) ;
return V_14 ;
}
static int F_21 ( struct V_58 * V_43 )
{
T_1 V_14 ;
if ( ! F_12 () )
return V_19 ;
V_14 = F_1 ( V_59 , 0 , V_22 , V_45 ,
0 , 0 , 0 , 0 , V_43 ,
sizeof( struct V_58 ) , NULL , 0 ) ;
return V_14 ;
}
int F_22 ( struct V_58 * V_43 )
{
int V_14 ;
V_14 = F_21 ( V_43 ) ;
if ( V_14 )
F_10 ( L_26 , V_14 ) ;
return V_14 ;
}
static int F_23 ( struct V_60 * V_43 )
{
T_1 V_14 ;
if ( ! F_12 () )
return V_61 ;
V_14 = F_1 ( V_62 , 0 , V_22 , 2 , V_22 , 4 ,
V_22 , V_45 , V_43 ,
sizeof( struct V_60 ) , NULL , 0 ) ;
return V_14 ;
}
int F_24 ( struct V_60 * V_43 )
{
int V_14 ;
V_14 = F_23 ( V_43 ) ;
if ( V_14 )
F_10 ( L_27 , V_14 ) ;
return V_14 ;
}
static int F_25 ( char * V_43 , T_2 V_63 )
{
T_1 V_14 ;
if ( ! F_12 () )
return V_61 ;
V_14 = F_1 ( V_64 , 0 , V_22 , V_23 , V_45 , 0 , 0 ,
0 , V_43 , 65536 , F_26 ( V_63 ) , 65536 ) ;
return V_14 ;
}
int F_27 ( char * V_43 , T_2 V_63 )
{
int V_14 ;
V_14 = F_25 ( V_43 , V_63 ) ;
if ( V_14 )
F_10 ( L_28 , V_14 ) ;
return V_14 ;
}
void F_28 ( union V_65 * V_66 )
{
int V_67 ;
F_29 ( & V_21 ) ;
V_68 . V_69 = V_66 -> V_70 . V_71 ;
V_68 . V_72 = V_73 ;
F_30 (i) {
struct V_15 * V_74 = F_3 ( V_67 ) ;
if ( ! V_74 )
continue;
F_31 ( & V_74 [ V_75 ] ,
( unsigned long ) & V_76 ) ;
F_31 ( & V_74 [ V_77 ] ,
( unsigned long ) F_26 ( V_66 -> V_70 . V_78 ) ) ;
F_31 ( & V_74 [ V_79 ] ,
( unsigned long ) F_26 ( V_66 -> V_70 . V_80 ) ) ;
}
}
