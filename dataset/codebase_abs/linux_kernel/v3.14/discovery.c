void F_1 ( T_1 * V_1 , T_2 * V_2 )
{
T_2 * V_3 , * V_4 ;
unsigned long V_5 ;
V_2 -> V_6 = V_2 -> V_7 ;
F_2 ( & V_1 -> V_8 , V_5 ) ;
V_3 = ( T_2 * ) F_3 ( V_1 ) ;
while ( V_3 != NULL ) {
V_4 = V_3 ;
V_3 = ( T_2 * ) F_4 ( V_1 ) ;
if ( ( V_4 -> V_9 . V_10 == V_2 -> V_9 . V_10 ) &&
( ( V_4 -> V_9 . V_11 == V_2 -> V_9 . V_11 ) ||
( strcmp ( V_4 -> V_9 . V_12 , V_2 -> V_9 . V_12 ) == 0 ) ) )
{
F_5 ( V_1 , ( V_13 * ) V_4 ) ;
if ( F_6 ( ( V_14 * ) V_4 -> V_9 . V_15 ) == F_6 ( ( V_14 * ) V_2 -> V_9 . V_15 ) )
V_2 -> V_6 = V_4 -> V_6 ;
F_7 ( V_4 ) ;
}
}
F_8 ( V_1 , ( V_13 * ) V_2 , V_2 -> V_9 . V_11 , NULL ) ;
F_9 ( & V_1 -> V_8 , V_5 ) ;
}
void F_10 ( T_1 * V_1 , T_1 * log )
{
T_2 * V_3 ;
F_11 ( 4 , L_1 , V_16 ) ;
if ( log == NULL ) {
return;
}
V_3 = ( T_2 * ) F_12 ( log ) ;
while ( V_3 != NULL ) {
F_1 ( V_1 , V_3 ) ;
V_3 = ( T_2 * ) F_12 ( log ) ;
}
F_13 ( log , ( V_17 ) F_7 ) ;
}
void F_14 ( T_1 * log , T_3 V_10 , int V_18 )
{
T_2 * V_3 ;
T_2 * V_19 ;
unsigned long V_5 ;
T_4 * V_20 = NULL ;
int V_21 ;
int V_22 = 0 ;
F_15 (log != NULL, return;) ;
F_11 ( 4 , L_1 , V_16 ) ;
F_2 ( & log -> V_8 , V_5 ) ;
V_3 = ( T_2 * ) F_3 ( log ) ;
while ( V_3 != NULL ) {
V_19 = V_3 ;
V_3 = ( T_2 * ) F_4 ( log ) ;
if ( ( V_19 -> V_9 . V_10 == V_10 ) &&
( V_18 ||
( ( V_23 - V_19 -> V_7 ) > V_24 ) ) )
{
if( V_20 == NULL ) {
V_21 = F_16 ( log ) ;
V_20 = F_17 ( V_21 * sizeof( struct V_25 ) , V_26 ) ;
if ( V_20 == NULL ) {
F_9 ( & log -> V_8 , V_5 ) ;
return;
}
}
memcpy ( & ( V_20 [ V_22 ] ) , & ( V_19 -> V_9 ) ,
sizeof( T_4 ) ) ;
V_22 ++ ;
V_19 = F_5 ( log , ( V_13 * ) V_19 ) ;
F_7 ( V_19 ) ;
}
}
F_9 ( & log -> V_8 , V_5 ) ;
if( V_20 == NULL )
return;
F_18 ( V_20 , V_22 ) ;
F_7 ( V_20 ) ;
}
struct V_25 * F_19 ( T_1 * log , int * V_27 ,
V_14 V_28 , int V_29 )
{
T_2 * V_3 ;
unsigned long V_5 ;
T_4 * V_20 = NULL ;
int V_30 = ( V_31 * V_32 ) ;
int V_21 ;
int V_22 = 0 ;
F_15 (pn != NULL, return NULL;) ;
F_15 (log != NULL, return NULL;) ;
F_2 ( & log -> V_8 , V_5 ) ;
V_3 = ( T_2 * ) F_3 ( log ) ;
while ( V_3 != NULL ) {
if ( ( F_6 ( ( V_14 * ) V_3 -> V_9 . V_15 ) & V_28 ) &&
( ( V_29 ) ||
( ( V_23 - V_3 -> V_6 ) < V_30 ) ) ) {
if( V_20 == NULL ) {
V_21 = F_16 ( log ) ;
V_20 = F_17 ( V_21 * sizeof( struct V_25 ) , V_26 ) ;
if ( V_20 == NULL ) {
F_9 ( & log -> V_8 , V_5 ) ;
return NULL ;
}
}
memcpy ( & ( V_20 [ V_22 ] ) , & ( V_3 -> V_9 ) ,
sizeof( T_4 ) ) ;
V_22 ++ ;
}
V_3 = ( T_2 * ) F_4 ( log ) ;
}
F_9 ( & log -> V_8 , V_5 ) ;
* V_27 = V_22 ;
return V_20 ;
}
static inline T_2 * F_20 ( T_5 V_33 )
{
T_2 * V_3 ;
for ( V_3 = ( T_2 * ) F_3 ( V_34 -> V_1 ) ;
V_3 != NULL ;
V_3 = ( T_2 * ) F_4 ( V_34 -> V_1 ) ) {
if ( V_33 -- == 0 )
break;
}
return V_3 ;
}
static void * F_21 ( struct V_35 * V_36 , T_5 * V_33 )
{
F_22 ( & V_34 -> V_1 -> V_8 ) ;
return * V_33 ? F_20 ( * V_33 - 1 ) : V_37 ;
}
static void * F_23 ( struct V_35 * V_36 , void * V_38 , T_5 * V_33 )
{
++ * V_33 ;
return ( V_38 == V_37 )
? ( void * ) F_3 ( V_34 -> V_1 )
: ( void * ) F_4 ( V_34 -> V_1 ) ;
}
static void F_24 ( struct V_35 * V_36 , void * V_38 )
{
F_25 ( & V_34 -> V_1 -> V_8 ) ;
}
static int F_26 ( struct V_35 * V_36 , void * V_38 )
{
if ( V_38 == V_37 )
F_27 ( V_36 , L_2 ) ;
else {
const T_2 * V_3 = V_38 ;
F_28 ( V_36 , L_3 ,
V_3 -> V_9 . V_12 ,
V_3 -> V_9 . V_15 [ 0 ] ,
V_3 -> V_9 . V_15 [ 1 ] ) ;
#if 0
if ( discovery->data.hints[0] & HINT_PNP)
seq_puts(seq, "PnP Compatible ");
if ( discovery->data.hints[0] & HINT_PDA)
seq_puts(seq, "PDA/Palmtop ");
if ( discovery->data.hints[0] & HINT_COMPUTER)
seq_puts(seq, "Computer ");
if ( discovery->data.hints[0] & HINT_PRINTER)
seq_puts(seq, "Printer ");
if ( discovery->data.hints[0] & HINT_MODEM)
seq_puts(seq, "Modem ");
if ( discovery->data.hints[0] & HINT_FAX)
seq_puts(seq, "Fax ");
if ( discovery->data.hints[0] & HINT_LAN)
seq_puts(seq, "LAN Access ");
if ( discovery->data.hints[1] & HINT_TELEPHONY)
seq_puts(seq, "Telephony ");
if ( discovery->data.hints[1] & HINT_FILE_SERVER)
seq_puts(seq, "File Server ");
if ( discovery->data.hints[1] & HINT_COMM)
seq_puts(seq, "IrCOMM ");
if ( discovery->data.hints[1] & HINT_OBEX)
seq_puts(seq, "IrOBEX ");
#endif
F_28 ( V_36 , L_4 ,
V_3 -> V_9 . V_10 ,
V_3 -> V_9 . V_11 ) ;
F_29 ( V_36 , '\n' ) ;
}
return 0 ;
}
static int F_30 ( struct V_39 * V_39 , struct V_40 * V_40 )
{
F_15 (irlmp != NULL, return -EINVAL;) ;
return F_31 ( V_40 , & V_41 ) ;
}
