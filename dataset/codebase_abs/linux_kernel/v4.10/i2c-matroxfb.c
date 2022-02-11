static int F_1 ( struct V_1 * V_2 ) {
unsigned long V_3 ;
int V_4 ;
F_2 ( V_3 ) ;
V_4 = F_3 ( V_2 , V_5 ) ;
F_4 ( V_3 ) ;
return V_4 ;
}
static void F_5 ( struct V_1 * V_2 , int V_6 , int V_7 ) {
unsigned long V_3 ;
int V_4 ;
F_2 ( V_3 ) ;
V_4 = ( F_3 ( V_2 , V_8 ) & V_6 ) | V_7 ;
F_6 ( V_2 , V_8 , V_4 ) ;
F_6 ( V_2 , V_5 , 0x00 ) ;
F_4 ( V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , int V_6 , int V_9 ) {
if ( V_9 )
V_9 = 0 ;
else
V_9 = V_6 ;
F_5 ( V_2 , ~ V_6 , V_9 ) ;
}
static void F_8 ( void * V_10 , int V_9 ) {
struct V_11 * V_12 = V_10 ;
F_7 ( V_12 -> V_2 , V_12 -> V_6 . V_10 , V_9 ) ;
}
static void F_9 ( void * V_10 , int V_9 ) {
struct V_11 * V_12 = V_10 ;
F_7 ( V_12 -> V_2 , V_12 -> V_6 . clock , V_9 ) ;
}
static int F_10 ( void * V_10 ) {
struct V_11 * V_12 = V_10 ;
return ( F_1 ( V_12 -> V_2 ) & V_12 -> V_6 . V_10 ) ? 1 : 0 ;
}
static int F_11 ( void * V_10 ) {
struct V_11 * V_12 = V_10 ;
return ( F_1 ( V_12 -> V_2 ) & V_12 -> V_6 . clock ) ? 1 : 0 ;
}
static int F_12 ( struct V_11 * V_12 , struct V_1 * V_2 ,
unsigned int V_10 , unsigned int clock , const char * V_13 ,
int V_14 )
{
int V_15 ;
V_12 -> V_2 = V_2 ;
V_12 -> V_6 . V_10 = V_10 ;
V_12 -> V_6 . clock = clock ;
V_12 -> V_16 . V_17 = V_18 ;
snprintf ( V_12 -> V_16 . V_13 , sizeof( V_12 -> V_16 . V_13 ) , V_13 ,
V_2 -> V_19 . V_20 ) ;
F_13 ( & V_12 -> V_16 , V_12 ) ;
V_12 -> V_16 . V_14 = V_14 ;
V_12 -> V_16 . V_21 = & V_12 -> V_22 ;
V_12 -> V_16 . V_23 . V_24 = & V_2 -> V_25 -> V_23 ;
V_12 -> V_22 = V_26 ;
V_12 -> V_22 . V_10 = V_12 ;
V_15 = F_14 ( & V_12 -> V_16 ) ;
V_12 -> V_27 = ! V_15 ;
return V_15 ;
}
static void F_15 ( struct V_11 * V_12 ) {
if ( V_12 -> V_27 ) {
F_16 ( & V_12 -> V_16 ) ;
V_12 -> V_27 = 0 ;
}
}
static inline void F_17 ( struct V_28 * V_29 ) {
F_15 ( & V_29 -> V_30 ) ;
}
static inline void F_18 ( struct V_28 * V_29 ) {
F_15 ( & V_29 -> V_31 ) ;
}
static inline void F_19 ( struct V_28 * V_29 ) {
F_15 ( & V_29 -> V_32 ) ;
}
static void * F_20 ( struct V_1 * V_2 ) {
int V_15 ;
unsigned long V_3 ;
struct V_28 * V_33 ;
V_33 = F_21 ( sizeof( * V_33 ) , V_34 ) ;
if ( ! V_33 )
return NULL ;
F_2 ( V_3 ) ;
F_6 ( V_2 , V_5 , 0xFF ) ;
F_6 ( V_2 , V_8 , 0x00 ) ;
F_4 ( V_3 ) ;
switch ( V_2 -> V_35 ) {
case V_36 :
case V_37 :
V_15 = F_12 ( & V_33 -> V_31 , V_2 ,
V_38 , V_39 ,
L_1 , V_40 ) ;
break;
default:
V_15 = F_12 ( & V_33 -> V_31 , V_2 ,
V_41 , V_42 ,
L_1 , V_40 ) ;
break;
}
if ( V_15 )
goto V_43;
if ( V_2 -> V_44 . V_45 ) {
V_15 = F_12 ( & V_33 -> V_32 , V_2 ,
V_46 , V_47 ,
L_2 , V_40 ) ;
if ( V_15 == - V_48 ) {
F_22 ( V_49 L_3 ) ;
} else if ( V_15 )
F_22 ( V_49 L_4 ) ;
V_15 = F_12 ( & V_33 -> V_30 , V_2 ,
V_50 , V_51 , L_5 , 0 ) ;
if ( V_15 )
F_22 ( V_49 L_6 ) ;
else {
struct V_52 V_53 = {
F_23 ( L_7 , 0x1b ) ,
} ;
unsigned short const V_54 [ 2 ] = {
0x1b , V_55
} ;
F_24 ( & V_33 -> V_30 . V_16 ,
& V_53 , V_54 , NULL ) ;
}
}
return V_33 ;
V_43: ;
F_25 ( V_33 ) ;
F_22 ( V_56 L_8 ) ;
return NULL ;
}
static void F_26 ( struct V_1 * V_2 , void * V_10 ) {
struct V_28 * V_33 = V_10 ;
F_17 ( V_33 ) ;
F_19 ( V_33 ) ;
F_18 ( V_33 ) ;
F_25 ( V_33 ) ;
}
static int T_1 F_27 ( void ) {
if ( F_28 ( & V_57 ) ) {
F_22 ( V_56 L_9 ) ;
return - V_58 ;
}
return 0 ;
}
static void T_2 F_29 ( void ) {
F_30 ( & V_57 ) ;
}
