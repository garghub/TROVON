static void * F_1 ( void )
{
if ( V_1 )
return NULL ;
V_1 = true ;
return & V_2 ;
}
static void F_2 ( void * T_1 V_3 )
{
V_1 = false ;
}
static unsigned long F_3 ( struct V_4 * V_5 )
{
struct V_6 V_7 ;
struct V_8 V_9 ;
unsigned long V_10 = 0 ;
if ( V_5 -> V_11 == ( V_12 * ) & V_13 )
return ( unsigned long ) V_5 -> V_11 + sizeof( V_12 ) ;
if ( ! F_4 ( ( unsigned long ) V_5 -> V_11 ) )
return 0 ;
memset ( & V_7 , 0 , sizeof( struct V_6 ) ) ;
V_7 . V_10 = ( unsigned long ) V_5 -> V_11 ;
V_7 . V_14 = 0x0 ;
V_7 . V_15 = V_16 ;
if ( ! F_5 ( * V_5 -> V_17 . V_18 ) &&
F_6 ( & V_9 , & V_7 , * V_5 -> V_17 . V_18 ) == 1 ) {
F_7 ( & V_7 , & V_9 ) ;
V_10 = V_7 . V_10 ;
}
return V_10 ;
}
static void F_8 ( struct V_19 * V_9 ,
struct V_6 * V_7 )
{
struct V_20 * V_21 = F_9 () ;
unsigned long V_22 ;
if ( F_10 ( & V_9 -> V_23 ) )
return;
F_11 ( V_22 ) ;
F_12 () ;
if ( F_13 () ) {
F_14 ( & V_9 -> V_23 ) ;
} else {
F_15 ( V_24 , & V_9 -> V_23 ) ;
V_7 -> V_10 = ( unsigned long ) V_9 -> V_23 . V_11 ;
V_21 -> V_25 = V_26 ;
F_16 ( & V_9 -> V_23 , V_7 ) ;
F_15 ( V_24 , NULL ) ;
}
F_17 ( V_22 ) ;
}
void F_18 ( struct V_19 * V_9 )
{
if ( V_9 -> V_27 . V_18 ) {
F_19 ( V_9 -> V_27 . V_18 , 1 ) ;
V_9 -> V_27 . V_18 = NULL ;
}
}
void F_20 ( unsigned int V_28 , V_12 * V_11 )
{
F_21 ( V_11 , V_29 | F_22 ( 4 ) |
( ( V_28 >> 16 ) & 0xffff ) ) ;
V_11 ++ ;
F_21 ( V_11 , V_30 | F_23 ( 4 ) |
F_24 ( 4 ) | ( V_28 & 0xffff ) ) ;
}
void F_25 ( unsigned long V_28 , V_12 * V_11 )
{
F_21 ( V_11 , V_29 | F_22 ( 3 ) |
( ( V_28 >> 48 ) & 0xffff ) ) ;
V_11 ++ ;
F_21 ( V_11 , V_30 | F_23 ( 3 ) |
F_24 ( 3 ) | ( ( V_28 >> 32 ) & 0xffff ) ) ;
V_11 ++ ;
F_21 ( V_11 , V_31 | F_23 ( 3 ) |
F_24 ( 3 ) | F_26 ( 32 ) | F_27 ( 31 ) ) ;
V_11 ++ ;
F_21 ( V_11 , V_32 | F_23 ( 3 ) |
F_24 ( 3 ) | ( ( V_28 >> 16 ) & 0xffff ) ) ;
V_11 ++ ;
F_21 ( V_11 , V_30 | F_23 ( 3 ) |
F_24 ( 3 ) | ( V_28 & 0xffff ) ) ;
}
int F_28 ( struct V_19 * V_9 , struct V_4 * V_5 )
{
V_12 * V_33 , V_34 , V_35 ;
V_12 * V_36 , * V_37 ;
long V_38 ;
unsigned long V_10 , V_39 ;
int V_40 , V_41 ;
V_42 . V_43 = V_44 ;
V_10 = F_3 ( V_5 ) ;
if ( ! V_10 )
return - V_45 ;
V_33 = F_29 () ;
if ( ! V_33 )
return - V_46 ;
V_38 = ( unsigned long ) V_33 - ( unsigned long ) V_5 -> V_11 ;
if ( ! F_30 ( V_38 ) )
goto error;
V_38 = ( unsigned long ) ( V_33 + V_47 ) -
( unsigned long ) V_10 ;
if ( ! F_30 ( V_38 ) )
goto error;
V_39 = ( V_48 * sizeof( V_12 ) ) / sizeof( int ) ;
F_31 ( L_1 , V_33 , V_39 ) ;
for ( V_41 = 0 ; V_41 < V_39 ; V_41 ++ ) {
V_40 = F_21 ( V_33 + V_41 , * ( V_49 + V_41 ) ) ;
if ( V_40 < 0 )
goto error;
}
F_25 ( ( unsigned long ) V_9 , V_33 + V_50 ) ;
V_36 = ( V_12 * ) F_32 ( L_2 ) ;
V_37 = ( V_12 * ) F_32 ( L_3 ) ;
if ( ! V_36 || ! V_37 ) {
F_33 ( 1 , L_4 ) ;
goto error;
}
V_34 = F_34 ( ( unsigned int * ) V_33 + V_51 ,
( unsigned long ) V_36 ,
V_52 ) ;
V_35 = F_34 ( ( unsigned int * ) V_33 + V_53 ,
( unsigned long ) V_37 ,
V_52 ) ;
if ( ! V_34 || ! V_35 )
goto error;
F_21 ( V_33 + V_51 , V_34 ) ;
F_21 ( V_33 + V_53 , V_35 ) ;
F_20 ( * V_5 -> V_17 . V_18 , V_33 + V_54 ) ;
F_35 ( V_33 + V_47 , ( unsigned long ) V_10 , 0 ) ;
F_36 ( ( unsigned long ) V_33 ,
( unsigned long ) ( & V_33 [ V_48 ] ) ) ;
V_9 -> V_27 . V_18 = V_33 ;
return 0 ;
error:
F_19 ( V_33 , 0 ) ;
return - V_55 ;
}
int F_37 ( struct V_56 * V_27 )
{
return V_27 -> V_18 != NULL ;
}
int F_38 ( struct V_19 * V_9 )
{
return 0 ;
}
void F_39 ( struct V_57 * V_58 )
{
struct V_19 * V_9 ;
struct V_19 * V_59 ;
F_40 (op, tmp, oplist, list) {
memcpy ( V_9 -> V_27 . V_60 , V_9 -> V_23 . V_11 ,
V_61 ) ;
F_21 ( V_9 -> V_23 . V_11 ,
F_34 ( ( unsigned int * ) V_9 -> V_23 . V_11 ,
( unsigned long ) V_9 -> V_27 . V_18 , 0 ) ) ;
F_41 ( & V_9 -> V_62 ) ;
}
}
void F_42 ( struct V_19 * V_9 )
{
F_43 ( & V_9 -> V_23 ) ;
}
void F_44 ( struct V_57 * V_58 ,
struct V_57 * V_63 )
{
struct V_19 * V_9 ;
struct V_19 * V_59 ;
F_40 (op, tmp, oplist, list) {
F_42 ( V_9 ) ;
F_45 ( & V_9 -> V_62 , V_63 ) ;
}
}
int F_46 ( struct V_19 * V_9 ,
unsigned long V_11 )
{
return ( ( unsigned long ) V_9 -> V_23 . V_11 <= V_11 &&
( unsigned long ) V_9 -> V_23 . V_11 + V_61 > V_11 ) ;
}
