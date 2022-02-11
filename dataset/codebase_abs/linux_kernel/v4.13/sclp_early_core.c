void F_1 ( void )
{
unsigned long V_1 , V_2 ;
T_1 V_3 , V_4 ;
union V_5 V_6 , V_7 ;
F_2 ( V_6 . V_8 , 0 , 0 ) ;
V_7 . V_8 = V_6 . V_8 & ~ V_9 ;
V_7 . V_10 = 0 ;
V_7 . V_11 = 1 ;
F_3 ( V_7 . V_8 , 0 , 0 ) ;
V_3 = V_12 . V_13 ;
V_1 = F_4 () ;
V_12 . V_13 . V_14 = V_1 ;
V_4 . V_14 = V_1 | V_15 | V_16 ;
V_12 . V_17 = 0 ;
do {
asm volatile(
" larl %[addr],0f\n"
" stg %[addr],%[psw_wait_addr]\n"
" stg %[addr],%[psw_ext_addr]\n"
" lpswe %[psw_wait]\n"
"0:\n"
: [addr] "=&d" (addr),
[psw_wait_addr] "=Q" (psw_wait.addr),
[psw_ext_addr] "=Q" (S390_lowcore.external_new_psw.addr)
: [psw_wait] "Q" (psw_wait)
: "cc", "memory");
} while ( V_12 . V_17 != V_18 );
V_12 . V_13 = V_3 ;
F_3 ( V_6 . V_8 , 0 , 0 ) ;
}
int F_5 ( T_2 V_19 , void * V_20 )
{
unsigned long V_21 ;
int V_22 ;
F_6 ( V_21 ) ;
V_22 = F_7 ( V_19 , V_20 ) ;
if ( V_22 )
goto V_23;
F_1 () ;
V_23:
F_8 ( V_21 ) ;
return V_22 ;
}
static void F_9 ( const char * V_24 , unsigned int V_25 )
{
unsigned char * V_26 , * V_27 , V_28 ;
unsigned int V_29 , V_30 ;
struct V_31 * V_20 ;
struct V_32 * V_33 ;
struct V_34 * V_34 ;
struct V_35 * V_35 ;
struct V_36 * V_36 ;
V_20 = (struct V_31 * ) & V_37 ;
V_27 = ( unsigned char * ) V_20 + sizeof( V_37 ) - 1 ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_26 = ( unsigned char * ) & V_20 -> V_33 . V_34 . V_35 ;
V_30 = 0 ;
do {
for ( V_29 = sizeof( * V_35 ) ; V_30 < V_25 ; V_29 ++ ) {
V_28 = V_24 [ V_30 ++ ] ;
if ( ( V_28 == 0x0a ) || ( V_26 + V_29 > V_27 ) )
break;
V_26 [ V_29 ] = V_38 [ V_28 ] ;
}
V_35 = (struct V_35 * ) V_26 ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
V_35 -> V_39 = V_29 ;
V_35 -> type = 4 ;
V_35 -> V_40 = V_41 ;
V_26 += V_29 ;
} while ( ( V_30 < V_25 ) && ( V_26 + sizeof( * V_35 ) <= V_27 ) );
V_25 = V_26 - ( unsigned char * ) V_20 ;
V_20 -> V_42 . V_39 = V_25 - F_10 ( struct V_31 , V_42 ) ;
V_33 = & V_20 -> V_33 ;
V_33 -> V_42 . type = V_43 ;
V_33 -> V_42 . V_39 = V_25 - F_10 ( struct V_31 , V_33 . V_42 ) ;
V_34 = & V_33 -> V_34 ;
V_34 -> V_42 . type = 1 ;
V_34 -> V_42 . V_44 = 0xD4C4C240 ;
V_34 -> V_42 . V_45 = 1 ;
V_34 -> V_42 . V_39 = V_25 - F_10 ( struct V_31 , V_33 . V_34 . V_42 ) ;
V_36 = & V_34 -> V_36 ;
V_36 -> V_39 = sizeof( * V_36 ) ;
V_36 -> type = 1 ;
F_5 ( V_46 , V_20 ) ;
}
static void F_11 ( const char * V_24 , unsigned int V_25 )
{
struct V_47 * V_20 ;
V_20 = (struct V_47 * ) & V_37 ;
if ( sizeof( * V_20 ) + V_25 >= sizeof( V_37 ) )
V_25 = sizeof( V_37 ) - sizeof( * V_20 ) ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
memcpy ( & V_20 -> V_33 . V_48 , V_24 , V_25 ) ;
V_20 -> V_42 . V_39 = sizeof( * V_20 ) + V_25 ;
V_20 -> V_33 . V_42 . V_39 = sizeof( V_20 -> V_33 ) + V_25 ;
V_20 -> V_33 . V_42 . type = V_49 ;
F_5 ( V_46 , V_20 ) ;
}
int F_12 ( struct V_50 * V_20 ,
unsigned long V_51 ,
unsigned long V_52 )
{
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_20 -> V_42 . V_39 = sizeof( * V_20 ) ;
V_20 -> V_53 = sizeof( V_54 ) ;
V_20 -> V_51 = V_51 ;
V_20 -> V_52 = V_52 ;
if ( F_5 ( V_55 , V_20 ) )
return - V_56 ;
if ( V_20 -> V_42 . V_57 != 0x20 )
return - V_56 ;
return 0 ;
}
unsigned int F_13 ( struct V_50 * V_20 )
{
if ( ! ( V_20 -> V_58 & V_59 ) )
return 0 ;
if ( ! ( V_20 -> V_60 & ( V_61 | V_62 ) ) )
return 0 ;
return 1 ;
}
static int F_14 ( int V_63 , int * V_64 , int * V_65 )
{
unsigned long V_51 , V_52 ;
struct V_50 * V_20 ;
int V_22 ;
* V_64 = * V_65 = 0 ;
V_20 = (struct V_50 * ) & V_37 ;
V_51 = V_63 ? 0 : V_59 ;
V_52 = V_63 ? 0 : V_66 | V_61 ;
V_22 = F_12 ( V_20 , V_51 , V_52 ) ;
if ( V_22 )
return V_22 ;
* V_64 = F_13 ( V_20 ) ;
* V_65 = V_20 -> V_52 & V_66 ;
return V_22 ;
}
void F_15 ( const char * V_24 , unsigned int V_25 )
{
int V_64 , V_65 ;
if ( V_67 != V_68 )
return;
if ( F_14 ( 0 , & V_64 , & V_65 ) != 0 )
return;
if ( V_64 )
F_9 ( V_24 , V_25 ) ;
if ( V_65 )
F_11 ( V_24 , V_25 ) ;
F_14 ( 1 , & V_64 , & V_65 ) ;
}
void F_16 ( const char * V_24 )
{
F_15 ( V_24 , strlen ( V_24 ) ) ;
}
