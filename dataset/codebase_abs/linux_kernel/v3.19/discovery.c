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
if ( log == NULL ) {
return;
}
V_3 = ( T_2 * ) F_11 ( log ) ;
while ( V_3 != NULL ) {
F_1 ( V_1 , V_3 ) ;
V_3 = ( T_2 * ) F_11 ( log ) ;
}
F_12 ( log , ( V_16 ) F_7 ) ;
}
void F_13 ( T_1 * log , T_3 V_10 , int V_17 )
{
T_2 * V_3 ;
T_2 * V_18 ;
unsigned long V_5 ;
T_4 * V_19 = NULL ;
int V_20 ;
int V_21 = 0 ;
F_14 (log != NULL, return;) ;
F_2 ( & log -> V_8 , V_5 ) ;
V_3 = ( T_2 * ) F_3 ( log ) ;
while ( V_3 != NULL ) {
V_18 = V_3 ;
V_3 = ( T_2 * ) F_4 ( log ) ;
if ( ( V_18 -> V_9 . V_10 == V_10 ) &&
( V_17 ||
( ( V_22 - V_18 -> V_7 ) > V_23 ) ) )
{
if( V_19 == NULL ) {
V_20 = F_15 ( log ) ;
V_19 = F_16 ( V_20 * sizeof( struct V_24 ) , V_25 ) ;
if ( V_19 == NULL ) {
F_9 ( & log -> V_8 , V_5 ) ;
return;
}
}
memcpy ( & ( V_19 [ V_21 ] ) , & ( V_18 -> V_9 ) ,
sizeof( T_4 ) ) ;
V_21 ++ ;
V_18 = F_5 ( log , ( V_13 * ) V_18 ) ;
F_7 ( V_18 ) ;
}
}
F_9 ( & log -> V_8 , V_5 ) ;
if( V_19 == NULL )
return;
F_17 ( V_19 , V_21 ) ;
F_7 ( V_19 ) ;
}
struct V_24 * F_18 ( T_1 * log , int * V_26 ,
V_14 V_27 , int V_28 )
{
T_2 * V_3 ;
unsigned long V_5 ;
T_4 * V_19 = NULL ;
int V_29 = ( V_30 * V_31 ) ;
int V_20 ;
int V_21 = 0 ;
F_14 (pn != NULL, return NULL;) ;
F_14 (log != NULL, return NULL;) ;
F_2 ( & log -> V_8 , V_5 ) ;
V_3 = ( T_2 * ) F_3 ( log ) ;
while ( V_3 != NULL ) {
if ( ( F_6 ( ( V_14 * ) V_3 -> V_9 . V_15 ) & V_27 ) &&
( ( V_28 ) ||
( ( V_22 - V_3 -> V_6 ) < V_29 ) ) ) {
if( V_19 == NULL ) {
V_20 = F_15 ( log ) ;
V_19 = F_16 ( V_20 * sizeof( struct V_24 ) , V_25 ) ;
if ( V_19 == NULL ) {
F_9 ( & log -> V_8 , V_5 ) ;
return NULL ;
}
}
memcpy ( & ( V_19 [ V_21 ] ) , & ( V_3 -> V_9 ) ,
sizeof( T_4 ) ) ;
V_21 ++ ;
}
V_3 = ( T_2 * ) F_4 ( log ) ;
}
F_9 ( & log -> V_8 , V_5 ) ;
* V_26 = V_21 ;
return V_19 ;
}
static inline T_2 * F_19 ( T_5 V_32 )
{
T_2 * V_3 ;
for ( V_3 = ( T_2 * ) F_3 ( V_33 -> V_1 ) ;
V_3 != NULL ;
V_3 = ( T_2 * ) F_4 ( V_33 -> V_1 ) ) {
if ( V_32 -- == 0 )
break;
}
return V_3 ;
}
static void * F_20 ( struct V_34 * V_35 , T_5 * V_32 )
{
F_21 ( & V_33 -> V_1 -> V_8 ) ;
return * V_32 ? F_19 ( * V_32 - 1 ) : V_36 ;
}
static void * F_22 ( struct V_34 * V_35 , void * V_37 , T_5 * V_32 )
{
++ * V_32 ;
return ( V_37 == V_36 )
? ( void * ) F_3 ( V_33 -> V_1 )
: ( void * ) F_4 ( V_33 -> V_1 ) ;
}
static void F_23 ( struct V_34 * V_35 , void * V_37 )
{
F_24 ( & V_33 -> V_1 -> V_8 ) ;
}
static int F_25 ( struct V_34 * V_35 , void * V_37 )
{
if ( V_37 == V_36 )
F_26 ( V_35 , L_1 ) ;
else {
const T_2 * V_3 = V_37 ;
F_27 ( V_35 , L_2 ,
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
F_27 ( V_35 , L_3 ,
V_3 -> V_9 . V_10 ,
V_3 -> V_9 . V_11 ) ;
F_28 ( V_35 , '\n' ) ;
}
return 0 ;
}
static int F_29 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
F_14 (irlmp != NULL, return -EINVAL;) ;
return F_30 ( V_39 , & V_40 ) ;
}
