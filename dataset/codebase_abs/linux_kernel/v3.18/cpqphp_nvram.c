static T_1 F_1 ( T_1 * * V_1 , T_2 V_2 , T_1 * V_3 , T_1 * V_4 )
{
T_2 * * V_5 ;
if ( ( * V_3 + 1 ) > * V_4 )
return ( 1 ) ;
* ( ( T_2 * ) * V_1 ) = V_2 ;
V_5 = ( T_2 * * ) V_1 ;
( * V_5 ) ++ ;
* V_3 += 1 ;
return ( 0 ) ;
}
static T_1 F_2 ( T_1 * * V_1 , T_1 V_2 , T_1 * V_3 , T_1 * V_4 )
{
if ( ( * V_3 + 4 ) > * V_4 )
return ( 1 ) ;
* * V_1 = V_2 ;
( * V_1 ) ++ ;
* V_3 += 4 ;
return ( 0 ) ;
}
static int F_3 ( void T_3 * V_6 )
{
T_2 V_7 , V_8 , V_9 , V_10 , V_11 , V_12 ;
int V_13 = 0 ;
V_7 = F_4 ( V_6 + 0xffea + 0 ) ;
V_8 = F_4 ( V_6 + 0xffea + 1 ) ;
V_9 = F_4 ( V_6 + 0xffea + 2 ) ;
V_10 = F_4 ( V_6 + 0xffea + 3 ) ;
V_11 = F_4 ( V_6 + 0xffea + 4 ) ;
V_12 = F_4 ( V_6 + 0xffea + 5 ) ;
if ( ( V_7 == 'C' ) &&
( V_8 == 'O' ) &&
( V_9 == 'M' ) &&
( V_10 == 'P' ) &&
( V_11 == 'A' ) &&
( V_12 == 'Q' ) ) {
V_13 = 1 ;
}
F_5 ( L_1 , V_14 , V_13 ) ;
return V_13 ;
}
static T_1 F_6 ( T_4 V_15 , T_2 * V_16 , T_2 * V_17 , T_1 * V_18 )
{
unsigned long V_19 ;
int V_20 = V_15 ;
int V_21 ;
if ( ! V_22 )
return - V_23 ;
F_7 ( & V_24 , V_19 ) ;
__asm__ (
"xorl %%ebx,%%ebx\n" \
"xorl %%edx,%%edx\n" \
"pushf\n" \
"push %%cs\n" \
"cli\n" \
"call *%6\n"
: "=c" (*buf_size), "=a" (ret_val)
: "a" (op), "c" (*buf_size), "S" (ev_name),
"D" (buffer), "m" (compaq_int15_entry_point)
: "%ebx", "%edx");
F_8 ( & V_24 , V_19 ) ;
return ( ( V_21 & 0xFF00 ) >> 8 ) ;
}
static int F_9 ( void T_3 * V_6 )
{
T_1 V_25 ;
T_1 V_26 ;
T_2 V_27 = 0xFF ;
T_1 V_28 ;
if ( ! F_3 ( V_6 ) )
return - V_23 ;
V_25 = 1024 ;
V_26 = V_25 ;
V_28 = F_6 ( V_29 , L_2 , V_30 , & V_26 ) ;
V_31 = V_26 ;
V_26 = 1 ;
V_28 = F_6 ( V_32 , L_2 , & V_27 , & V_26 ) ;
return V_28 ;
}
static T_1 F_10 ( void T_3 * V_6 )
{
T_1 * V_17 ;
T_1 * V_33 ;
T_1 V_34 ;
T_1 V_25 ;
T_1 V_26 ;
T_1 V_28 ;
T_2 V_35 ;
T_2 V_36 = 0 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
V_25 = 1024 ;
if ( ! F_3 ( V_6 ) )
return ( 1 ) ;
V_17 = ( T_1 * ) V_30 ;
if ( ! V_17 )
return ( 1 ) ;
V_33 = V_17 ;
V_34 = 0 ;
V_42 = (struct V_41 * ) V_33 ;
V_38 = V_45 ;
V_28 = F_1 ( & V_33 , 1 + V_38 -> V_46 , & V_34 , & V_25 ) ;
if ( V_28 )
return ( V_28 ) ;
V_28 = F_1 ( & V_33 , 1 , & V_34 , & V_25 ) ;
if ( V_28 )
return ( V_28 ) ;
while ( V_38 ) {
V_44 = (struct V_43 * ) V_33 ;
V_36 ++ ;
V_28 = F_1 ( & V_33 , V_38 -> V_47 , & V_34 , & V_25 ) ;
if ( V_28 )
return ( V_28 ) ;
V_28 = F_1 ( & V_33 , F_11 ( V_38 -> V_48 -> V_49 ) , & V_34 , & V_25 ) ;
if ( V_28 )
return ( V_28 ) ;
V_28 = F_1 ( & V_33 , F_12 ( V_38 -> V_48 -> V_49 ) , & V_34 , & V_25 ) ;
if ( V_28 )
return ( V_28 ) ;
V_28 = F_2 ( & V_33 , 0 , & V_34 , & V_25 ) ;
if ( V_28 )
return ( V_28 ) ;
V_40 = V_38 -> V_50 ;
V_35 = 0 ;
while ( V_40 ) {
V_35 ++ ;
V_28 = F_2 ( & V_33 , V_40 -> V_51 , & V_34 , & V_25 ) ;
if ( V_28 )
return ( V_28 ) ;
V_28 = F_2 ( & V_33 , V_40 -> V_52 , & V_34 , & V_25 ) ;
if ( V_28 )
return ( V_28 ) ;
V_40 = V_40 -> V_53 ;
}
V_44 -> V_54 = V_35 ;
V_40 = V_38 -> V_55 ;
V_35 = 0 ;
while ( V_40 ) {
V_35 ++ ;
V_28 = F_2 ( & V_33 , V_40 -> V_51 , & V_34 , & V_25 ) ;
if ( V_28 )
return ( V_28 ) ;
V_28 = F_2 ( & V_33 , V_40 -> V_52 , & V_34 , & V_25 ) ;
if ( V_28 )
return ( V_28 ) ;
V_40 = V_40 -> V_53 ;
}
V_44 -> V_56 = V_35 ;
V_40 = V_38 -> V_57 ;
V_35 = 0 ;
while ( V_40 ) {
V_35 ++ ;
V_28 = F_2 ( & V_33 , V_40 -> V_51 , & V_34 , & V_25 ) ;
if ( V_28 )
return ( V_28 ) ;
V_28 = F_2 ( & V_33 , V_40 -> V_52 , & V_34 , & V_25 ) ;
if ( V_28 )
return ( V_28 ) ;
V_40 = V_40 -> V_53 ;
}
V_44 -> V_58 = V_35 ;
V_40 = V_38 -> V_59 ;
V_35 = 0 ;
while ( V_40 ) {
V_35 ++ ;
V_28 = F_2 ( & V_33 , V_40 -> V_51 , & V_34 , & V_25 ) ;
if ( V_28 )
return ( V_28 ) ;
V_28 = F_2 ( & V_33 , V_40 -> V_52 , & V_34 , & V_25 ) ;
if ( V_28 )
return ( V_28 ) ;
V_40 = V_40 -> V_53 ;
}
V_44 -> V_60 = V_35 ;
V_38 = V_38 -> V_53 ;
}
V_42 -> V_61 = V_36 ;
V_26 = V_34 ;
V_28 = F_6 ( V_32 , L_2 , ( T_2 * ) V_17 , & V_26 ) ;
F_5 ( L_3 , V_34 , V_26 ) ;
V_31 = V_26 ;
if ( V_28 ) {
F_13 ( V_62 ) ;
return ( 1 ) ;
}
return ( 0 ) ;
}
void F_14 ( void T_3 * V_6 )
{
if ( V_6 )
V_22 = ( V_6 + V_63 - V_64 ) ;
F_5 ( L_4 , V_22 ) ;
F_15 ( & V_24 ) ;
}
int F_16 ( void T_3 * V_6 , struct V_37 * V_38 )
{
T_2 V_47 , V_65 , V_66 ;
T_2 V_67 , V_68 , V_69 , V_70 ;
T_1 V_28 ;
T_2 * V_71 ;
struct V_39 * V_72 ;
struct V_39 * V_73 ;
struct V_39 * V_74 ;
struct V_39 * V_75 ;
struct V_43 * V_44 ;
struct V_41 * V_42 ;
if ( ! V_76 ) {
if ( F_9 ( V_6 ) )
memset ( V_30 , 0 , 1024 ) ;
V_76 = 1 ;
}
V_42 = (struct V_41 * ) V_30 ;
if ( ( V_42 -> V_77 == 2 ) ||
( ( V_42 -> V_77 == 1 ) && ! V_38 -> V_46 ) ) {
V_71 = & ( V_42 -> V_53 ) ;
V_44 = (struct V_43 * ) & ( V_42 -> V_53 ) ;
V_71 += 3 ;
if ( V_71 > ( ( T_2 * ) V_42 + V_31 ) )
return 2 ;
V_47 = V_44 -> V_47 ;
V_65 = V_44 -> V_65 ;
V_66 = V_44 -> V_66 ;
while ( ( V_47 != V_38 -> V_47 ) ||
( V_65 != F_11 ( V_38 -> V_48 -> V_49 ) ) ||
( V_66 != F_12 ( V_38 -> V_48 -> V_49 ) ) ) {
V_67 = V_44 -> V_54 ;
V_68 = V_44 -> V_56 ;
V_69 = V_44 -> V_58 ;
V_70 = V_44 -> V_60 ;
V_71 += 4 ;
if ( V_71 > ( ( T_2 * ) V_42 + V_31 ) )
return 2 ;
V_71 += ( V_67 + V_68 + V_69 + V_70 ) * 8 ;
if ( V_71 > ( ( T_2 * ) V_42 + V_31 ) )
return 2 ;
V_44 = (struct V_43 * ) V_71 ;
V_71 += 3 ;
if ( V_71 > ( ( T_2 * ) V_42 + V_31 ) )
return 2 ;
V_47 = V_44 -> V_47 ;
V_65 = V_44 -> V_65 ;
V_66 = V_44 -> V_66 ;
}
V_67 = V_44 -> V_54 ;
V_68 = V_44 -> V_56 ;
V_69 = V_44 -> V_58 ;
V_70 = V_44 -> V_60 ;
V_71 += 4 ;
if ( V_71 > ( ( T_2 * ) V_42 + V_31 ) )
return 2 ;
while ( V_67 -- ) {
V_72 = F_17 ( sizeof( struct V_39 ) , V_78 ) ;
if ( ! V_72 )
break;
V_72 -> V_51 = * ( T_1 * ) V_71 ;
F_5 ( L_5 , V_72 -> V_51 ) ;
V_71 += 4 ;
if ( V_71 > ( ( T_2 * ) V_42 + V_31 ) ) {
F_18 ( V_72 ) ;
return 2 ;
}
V_72 -> V_52 = * ( T_1 * ) V_71 ;
F_5 ( L_6 , V_72 -> V_52 ) ;
V_71 += 4 ;
if ( V_71 > ( ( T_2 * ) V_42 + V_31 ) ) {
F_18 ( V_72 ) ;
return 2 ;
}
V_72 -> V_53 = V_38 -> V_50 ;
V_38 -> V_50 = V_72 ;
}
while ( V_68 -- ) {
V_73 = F_17 ( sizeof( struct V_39 ) , V_78 ) ;
if ( ! V_73 )
break;
V_73 -> V_51 = * ( T_1 * ) V_71 ;
F_5 ( L_7 , V_73 -> V_51 ) ;
V_71 += 4 ;
if ( V_71 > ( ( T_2 * ) V_42 + V_31 ) ) {
F_18 ( V_73 ) ;
return 2 ;
}
V_73 -> V_52 = * ( T_1 * ) V_71 ;
F_5 ( L_8 , V_73 -> V_52 ) ;
V_71 += 4 ;
if ( V_71 > ( ( T_2 * ) V_42 + V_31 ) ) {
F_18 ( V_73 ) ;
return 2 ;
}
V_73 -> V_53 = V_38 -> V_55 ;
V_38 -> V_55 = V_73 ;
}
while ( V_69 -- ) {
V_74 = F_17 ( sizeof( struct V_39 ) , V_78 ) ;
if ( ! V_74 )
break;
V_74 -> V_51 = * ( T_1 * ) V_71 ;
F_5 ( L_9 , V_74 -> V_51 ) ;
V_71 += 4 ;
if ( V_71 > ( ( T_2 * ) V_42 + V_31 ) ) {
F_18 ( V_74 ) ;
return 2 ;
}
V_74 -> V_52 = * ( T_1 * ) V_71 ;
F_5 ( L_10 , V_74 -> V_52 ) ;
V_71 += 4 ;
if ( V_71 > ( ( T_2 * ) V_42 + V_31 ) ) {
F_18 ( V_74 ) ;
return 2 ;
}
V_74 -> V_53 = V_38 -> V_57 ;
V_38 -> V_57 = V_74 ;
}
while ( V_70 -- ) {
V_75 = F_17 ( sizeof( struct V_39 ) , V_78 ) ;
if ( ! V_75 )
break;
V_75 -> V_51 = * ( T_1 * ) V_71 ;
V_71 += 4 ;
if ( V_71 > ( ( T_2 * ) V_42 + V_31 ) ) {
F_18 ( V_75 ) ;
return 2 ;
}
V_75 -> V_52 = * ( T_1 * ) V_71 ;
V_71 += 4 ;
if ( V_71 > ( ( T_2 * ) V_42 + V_31 ) ) {
F_18 ( V_75 ) ;
return 2 ;
}
V_75 -> V_53 = V_38 -> V_59 ;
V_38 -> V_59 = V_75 ;
}
V_28 = 1 ;
V_28 &= F_19 ( & ( V_38 -> V_50 ) ) ;
V_28 &= F_19 ( & ( V_38 -> V_55 ) ) ;
V_28 &= F_19 ( & ( V_38 -> V_57 ) ) ;
V_28 &= F_19 ( & ( V_38 -> V_59 ) ) ;
if ( V_28 )
return ( V_28 ) ;
} else {
if ( ( V_30 [ 0 ] != 0 ) && ( ! V_38 -> V_46 ) )
return 1 ;
}
return 0 ;
}
int F_20 ( void T_3 * V_6 )
{
int V_28 = 1 ;
if ( V_6 == NULL )
return - V_23 ;
if ( V_76 ) {
V_28 = F_10 ( V_6 ) ;
if ( V_28 )
F_13 ( V_62 ) ;
}
return V_28 ;
}
