int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
enum V_4 V_5 ,
unsigned short V_6 )
{
unsigned int V_7 ;
T_1 * V_8 ;
bool V_9 ;
int V_10 ;
V_9 = false ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
if ( V_12 [ V_7 ] == V_3 ) {
V_9 = true ;
break;
}
}
if ( ! V_9 )
return - V_13 ;
V_8 = F_2 ( 8 , V_14 ) ;
if ( V_8 == NULL )
return - V_15 ;
V_8 [ 0 ] = 0x00 ;
V_8 [ 1 ] = 0xff ;
if ( V_5 == V_16 )
V_8 [ 2 ] = 0x19 ;
else
V_8 [ 2 ] = 0x18 ;
V_8 [ 3 ] = 0xff & V_6 ;
V_8 [ 4 ] = 0x90 ;
V_8 [ 5 ] = 0x07 & V_7 ;
V_8 [ 6 ] = 0xff ;
V_8 [ 7 ] = 0xff ;
V_10 = F_3 ( V_2 , V_8 , 8 , V_8 , 8 ,
F_4 ( 1 ) | F_4 ( 2 ) | F_4 ( 3 ) | F_4 ( 4 ) | F_4 ( 5 ) ) ;
if ( V_10 < 0 )
;
else if ( V_10 < 8 )
V_10 = - V_17 ;
else if ( V_8 [ 0 ] == 0x08 )
V_10 = - V_18 ;
else if ( V_8 [ 0 ] == 0x0a )
V_10 = - V_13 ;
if ( V_10 < 0 )
goto V_19;
V_10 = 0 ;
V_19:
F_5 ( V_8 ) ;
return V_10 ;
}
int F_6 ( struct V_1 * V_2 , unsigned int * V_3 ,
enum V_4 V_5 ,
unsigned short V_6 )
{
unsigned int V_7 ;
T_1 * V_8 ;
int V_10 ;
V_8 = F_2 ( 8 , V_14 ) ;
if ( V_8 == NULL )
return - V_15 ;
V_8 [ 0 ] = 0x01 ;
V_8 [ 1 ] = 0xff ;
if ( V_5 == V_16 )
V_8 [ 2 ] = 0x19 ;
else
V_8 [ 2 ] = 0x18 ;
V_8 [ 3 ] = 0xff & V_6 ;
V_8 [ 4 ] = 0x90 ;
V_8 [ 5 ] = 0xff ;
V_8 [ 6 ] = 0xff ;
V_8 [ 7 ] = 0xff ;
V_10 = F_3 ( V_2 , V_8 , 8 , V_8 , 8 ,
F_4 ( 1 ) | F_4 ( 2 ) | F_4 ( 3 ) | F_4 ( 4 ) ) ;
if ( V_10 < 0 )
;
else if ( V_10 < 8 )
V_10 = - V_17 ;
else if ( V_8 [ 0 ] == 0x08 )
V_10 = - V_18 ;
else if ( V_8 [ 0 ] == 0x0a )
V_10 = - V_13 ;
else if ( V_8 [ 0 ] == 0x0b )
V_10 = - V_20 ;
if ( V_10 < 0 )
goto V_19;
V_7 = 0x07 & V_8 [ 5 ] ;
if ( V_7 >= V_11 ) {
V_10 = - V_20 ;
goto V_19;
}
* V_3 = V_12 [ V_7 ] ;
V_10 = 0 ;
V_19:
F_5 ( V_8 ) ;
return V_10 ;
}
int F_7 ( struct V_1 * V_2 , unsigned int V_21 ,
unsigned int V_22 , unsigned int V_23 ,
T_1 V_24 [ V_25 ] )
{
T_1 * V_8 ;
int V_10 ;
if ( ( V_21 == 0x1E ) || ( V_22 == 5 ) )
return - V_13 ;
V_8 = F_2 ( 8 , V_14 ) ;
if ( V_8 == NULL )
return - V_15 ;
V_8 [ 0 ] = 0x01 ;
V_8 [ 1 ] = ( ( V_21 & 0x1f ) << 3 ) | ( V_22 & 0x7 ) ;
V_8 [ 2 ] = 0x02 ;
V_8 [ 3 ] = 0xff & V_23 ;
V_10 = F_3 ( V_2 , V_8 , 8 , V_8 , 8 , F_4 ( 1 ) | F_4 ( 2 ) ) ;
if ( V_10 < 0 )
;
else if ( V_10 < 8 )
V_10 = - V_17 ;
else if ( V_8 [ 0 ] == 0x08 )
V_10 = - V_18 ;
else if ( V_8 [ 0 ] == 0x0a )
V_10 = - V_13 ;
else if ( V_8 [ 0 ] == 0x0b )
V_10 = - V_20 ;
if ( V_10 < 0 )
goto V_19;
V_24 [ 0 ] = V_8 [ 4 ] ;
V_24 [ 1 ] = V_8 [ 5 ] ;
V_24 [ 2 ] = V_8 [ 6 ] ;
V_24 [ 3 ] = V_8 [ 7 ] ;
V_10 = 0 ;
V_19:
F_5 ( V_8 ) ;
return V_10 ;
}
int F_3 ( struct V_1 * V_2 ,
const void * V_26 , unsigned int V_27 ,
void * V_28 , unsigned int V_29 ,
unsigned int V_30 )
{
struct V_31 V_32 ;
int V_33 , V_34 , V_35 = 0 ;
V_32 . V_2 = V_2 ;
V_32 . V_36 = V_28 ;
V_32 . V_29 = V_29 ;
V_32 . V_30 = V_30 ;
V_32 . V_37 = V_38 ;
F_8 ( & V_32 . V_39 ) ;
if ( * ( const T_1 * ) V_26 == 0x00 || * ( const T_1 * ) V_26 == 0x03 )
V_32 . V_40 = true ;
F_9 ( & V_41 ) ;
F_10 ( & V_32 . V_42 , & V_43 ) ;
F_11 ( & V_41 ) ;
for (; ; ) {
V_33 = V_27 == 4 ? V_44
: V_45 ;
V_34 = F_12 ( V_32 . V_2 , V_33 ,
V_46 + V_47 ,
( void * ) V_26 , V_27 , 0 ) ;
if ( V_34 < 0 )
break;
V_48:
F_13 ( V_32 . V_39 , V_32 . V_37 != V_38 ,
F_14 ( V_49 ) ) ;
if ( V_32 . V_37 == V_50 ) {
V_32 . V_37 = V_38 ;
goto V_48;
} else if ( V_32 . V_37 == V_51 ) {
V_34 = V_32 . V_29 ;
break;
} else if ( V_32 . V_37 == V_52 ) {
F_15 ( V_53 ) ;
} else if ( ++ V_35 >= V_54 ) {
F_16 ( & V_32 . V_2 -> V_55 , L_1 ) ;
V_34 = - V_17 ;
break;
}
}
F_9 ( & V_41 ) ;
F_17 ( & V_32 . V_42 ) ;
F_11 ( & V_41 ) ;
return V_34 ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
F_9 ( & V_41 ) ;
F_19 (t, &transactions, list) {
if ( V_32 -> V_2 == V_2 &&
( V_32 -> V_37 == V_38 ||
V_32 -> V_37 == V_50 ) ) {
V_32 -> V_37 = V_52 ;
F_20 ( & V_32 -> V_39 ) ;
}
}
F_11 ( & V_41 ) ;
}
static bool F_21 ( struct V_31 * V_56 ,
const void * V_28 , T_2 V_57 )
{
const T_1 * V_58 , * V_59 ;
unsigned int V_60 , V_61 ;
V_58 = V_28 ;
V_59 = V_56 -> V_36 ;
V_60 = V_56 -> V_30 ;
for ( V_61 = 0 ; ; ++ V_61 ) {
if ( ( V_60 & 1 ) && V_58 [ V_61 ] != V_59 [ V_61 ] )
return false ;
V_60 >>= 1 ;
if ( ! V_60 )
return true ;
if ( -- V_57 == 0 )
return false ;
}
}
static void F_22 ( struct V_62 * V_63 , struct V_64 * V_65 ,
int V_33 , int V_66 , int V_67 ,
int V_68 , unsigned long long V_69 ,
void * V_70 , T_2 V_57 , void * V_71 )
{
struct V_31 * V_32 ;
unsigned long V_72 ;
if ( V_57 < 1 || ( * ( const T_1 * ) V_70 & 0xf0 ) != V_73 )
return;
F_23 ( & V_41 , V_72 ) ;
F_19 (t, &transactions, list) {
struct V_74 * V_55 = F_24 ( V_32 -> V_2 ) ;
if ( V_55 -> V_63 != V_63 ||
V_55 -> V_68 != V_68 )
continue;
F_25 () ;
if ( V_55 -> V_75 != V_67 )
continue;
if ( V_32 -> V_37 == V_38 &&
F_21 ( V_32 , V_70 , V_57 ) ) {
if ( V_32 -> V_40 && * ( const T_1 * ) V_70 == 0x0f ) {
V_32 -> V_37 = V_50 ;
} else {
V_32 -> V_37 = V_51 ;
V_32 -> V_29 = F_26 (unsigned int, length,
t->response_size) ;
memcpy ( V_32 -> V_36 , V_70 ,
V_32 -> V_29 ) ;
}
F_20 ( & V_32 -> V_39 ) ;
}
}
F_27 ( & V_41 , V_72 ) ;
}
static int T_3 F_28 ( void )
{
static const struct V_76 V_77 = {
. V_78 = V_46 + V_79 ,
. V_19 = V_46 + V_80 ,
} ;
F_29 ( & V_81 ,
& V_77 ) ;
return 0 ;
}
static void T_4 F_30 ( void )
{
F_31 ( ! F_32 ( & V_43 ) ) ;
F_33 ( & V_81 ) ;
}
