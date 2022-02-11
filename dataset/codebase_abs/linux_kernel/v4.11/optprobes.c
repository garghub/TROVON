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
F_6 ( & V_9 , & V_7 , * V_5 -> V_17 . V_18 ) )
V_10 = V_7 . V_10 ;
return V_10 ;
}
static void F_7 ( struct V_19 * V_9 ,
struct V_6 * V_7 )
{
struct V_20 * V_21 = F_8 () ;
unsigned long V_22 ;
if ( F_9 ( & V_9 -> V_23 ) )
return;
F_10 ( V_22 ) ;
F_11 () ;
if ( F_12 () ) {
F_13 ( & V_9 -> V_23 ) ;
} else {
F_14 ( V_24 , & V_9 -> V_23 ) ;
V_7 -> V_10 = ( unsigned long ) V_9 -> V_23 . V_11 ;
V_21 -> V_25 = V_26 ;
F_15 ( & V_9 -> V_23 , V_7 ) ;
F_14 ( V_24 , NULL ) ;
}
F_16 ( V_22 ) ;
}
void F_17 ( struct V_19 * V_9 )
{
if ( V_9 -> V_27 . V_18 ) {
F_18 ( V_9 -> V_27 . V_18 , 1 ) ;
V_9 -> V_27 . V_18 = NULL ;
}
}
void F_19 ( unsigned int V_28 , V_12 * V_11 )
{
* V_11 ++ = V_29 | F_20 ( 4 ) |
( ( V_28 >> 16 ) & 0xffff ) ;
* V_11 = V_30 | F_21 ( 4 ) | F_22 ( 4 ) |
( V_28 & 0xffff ) ;
}
void F_23 ( unsigned long V_28 , V_12 * V_11 )
{
* V_11 ++ = V_29 | F_20 ( 3 ) |
( ( V_28 >> 48 ) & 0xffff ) ;
* V_11 ++ = V_30 | F_21 ( 3 ) | F_22 ( 3 ) |
( ( V_28 >> 32 ) & 0xffff ) ;
* V_11 ++ = V_31 | F_21 ( 3 ) | F_22 ( 3 ) |
F_24 ( 32 ) | F_25 ( 31 ) ;
* V_11 ++ = V_32 | F_21 ( 3 ) | F_22 ( 3 ) |
( ( V_28 >> 16 ) & 0xffff ) ;
* V_11 = V_30 | F_21 ( 3 ) | F_22 ( 3 ) |
( V_28 & 0xffff ) ;
}
int F_26 ( struct V_19 * V_9 , struct V_4 * V_5 )
{
V_12 * V_33 , V_34 , V_35 ;
V_12 * V_36 , * V_37 ;
long V_38 ;
unsigned long V_10 ;
V_39 . V_40 = V_41 ;
V_10 = F_3 ( V_5 ) ;
if ( ! V_10 )
return - V_42 ;
V_33 = F_27 () ;
if ( ! V_33 )
return - V_43 ;
V_38 = ( unsigned long ) V_33 - ( unsigned long ) V_5 -> V_11 ;
if ( ! F_28 ( V_38 ) )
goto error;
V_38 = ( unsigned long ) ( V_33 + V_44 ) -
( unsigned long ) V_10 ;
if ( ! F_28 ( V_38 ) )
goto error;
memcpy ( V_33 , V_45 ,
V_46 * sizeof( V_12 ) ) ;
F_23 ( ( unsigned long ) V_9 , V_33 + V_47 ) ;
F_29 ( L_1 , V_36 ) ;
F_29 ( L_2 , V_37 ) ;
if ( ! V_36 || ! V_37 ) {
F_30 ( 1 , L_3 ) ;
goto error;
}
V_34 = F_31 ( ( unsigned int * ) V_33 + V_48 ,
( unsigned long ) V_36 ,
V_49 ) ;
V_35 = F_31 ( ( unsigned int * ) V_33 + V_50 ,
( unsigned long ) V_37 ,
V_49 ) ;
if ( ! V_34 || ! V_35 )
goto error;
V_33 [ V_48 ] = V_34 ;
V_33 [ V_50 ] = V_35 ;
F_19 ( * V_5 -> V_17 . V_18 , V_33 + V_51 ) ;
V_33 [ V_44 ] = F_31 ( ( unsigned int * ) V_33 + V_44 ,
( unsigned long ) V_10 , 0 ) ;
F_32 ( ( unsigned long ) V_33 ,
( unsigned long ) ( & V_33 [ V_46 ] ) ) ;
V_9 -> V_27 . V_18 = V_33 ;
return 0 ;
error:
F_18 ( V_33 , 0 ) ;
return - V_52 ;
}
int F_33 ( struct V_53 * V_27 )
{
return V_27 -> V_18 != NULL ;
}
int F_34 ( struct V_19 * V_9 )
{
return 0 ;
}
void F_35 ( struct V_54 * V_55 )
{
struct V_19 * V_9 ;
struct V_19 * V_56 ;
F_36 (op, tmp, oplist, list) {
memcpy ( V_9 -> V_27 . V_57 , V_9 -> V_23 . V_11 ,
V_58 ) ;
F_37 ( V_9 -> V_23 . V_11 ,
F_31 ( ( unsigned int * ) V_9 -> V_23 . V_11 ,
( unsigned long ) V_9 -> V_27 . V_18 , 0 ) ) ;
F_38 ( & V_9 -> V_59 ) ;
}
}
void F_39 ( struct V_19 * V_9 )
{
F_40 ( & V_9 -> V_23 ) ;
}
void F_41 ( struct V_54 * V_55 ,
struct V_54 * V_60 )
{
struct V_19 * V_9 ;
struct V_19 * V_56 ;
F_36 (op, tmp, oplist, list) {
F_39 ( V_9 ) ;
F_42 ( & V_9 -> V_59 , V_60 ) ;
}
}
int F_43 ( struct V_19 * V_9 ,
unsigned long V_11 )
{
return ( ( unsigned long ) V_9 -> V_23 . V_11 <= V_11 &&
( unsigned long ) V_9 -> V_23 . V_11 + V_58 > V_11 ) ;
}
