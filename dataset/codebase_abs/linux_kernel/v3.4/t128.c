void T_1 F_1 ( char * V_1 , int * V_2 ) {
static int V_3 = 0 ;
int V_4 ;
if ( V_2 [ 0 ] != 2 )
F_2 ( L_1 ) ;
else
if ( V_3 < V_5 ) {
V_6 [ V_3 ] . V_7 = V_2 [ 1 ] ;
V_6 [ V_3 ] . V_8 = V_2 [ 2 ] ;
for ( V_4 = 0 ; V_4 < V_9 ; ++ V_4 )
if ( V_10 [ V_4 ] . V_7 == V_2 [ 1 ] ) {
V_10 [ V_4 ] . V_11 = 1 ;
break;
}
++ V_3 ;
}
}
int T_1 F_3 ( struct V_12 * V_13 ) {
static int V_14 = 0 , V_15 = 0 ;
struct V_16 * V_17 ;
unsigned long V_18 ;
void T_2 * V_19 ;
int V_20 , V_21 ;
V_13 -> V_22 = L_2 ;
V_13 -> V_23 = & V_24 ;
for ( V_21 = 0 ; V_14 < V_5 ; ++ V_14 ) {
V_18 = 0 ;
V_19 = NULL ;
if ( V_6 [ V_14 ] . V_7 ) {
V_18 = V_6 [ V_14 ] . V_7 ;
V_19 = F_4 ( V_10 [ V_15 ] . V_7 , 0x2000 ) ;
if ( ! V_19 )
V_18 = 0 ;
} else
for (; ! V_18 && ( V_15 < V_9 ) ; ++ V_15 ) {
#if ( V_25 & V_26 )
F_2 ( L_3 , V_10 [ V_15 ] . V_7 ) ;
#endif
if ( V_10 [ V_15 ] . V_11 )
continue;
V_19 = F_4 ( V_10 [ V_15 ] . V_7 , 0x2000 ) ;
if ( ! V_19 )
continue;
for ( V_20 = 0 ; V_20 < V_27 ; ++ V_20 )
if ( F_5 ( V_19 + V_28 [ V_20 ] . V_29 ,
V_28 [ V_20 ] . string ,
strlen ( V_28 [ V_20 ] . string ) ) ) {
V_18 = V_10 [ V_15 ] . V_7 ;
#if ( V_25 & V_26 )
F_2 ( L_4 ) ;
#endif
goto V_30;
}
F_6 ( V_19 ) ;
}
#if F_7 ( V_25 ) && ( V_25 & V_26 )
F_2 ( L_5 , ( unsigned int ) V_18 ) ;
#endif
if ( ! V_18 )
break;
V_30:
V_17 = F_8 ( V_13 , sizeof( struct V_31 ) ) ;
if( V_17 == NULL )
break;
V_17 -> V_18 = V_18 ;
( (struct V_31 * ) V_17 -> V_32 ) -> V_18 = V_19 ;
F_9 ( V_17 , 0 ) ;
if ( V_6 [ V_14 ] . V_8 != V_33 )
V_17 -> V_8 = V_6 [ V_14 ] . V_8 ;
else
V_17 -> V_8 = F_10 ( V_17 , V_34 ) ;
if ( V_17 -> V_8 != V_35 )
if ( F_11 ( V_17 -> V_8 , V_36 , V_37 , L_2 ,
V_17 ) ) {
F_2 ( L_6 ,
V_17 -> V_38 , V_17 -> V_8 ) ;
V_17 -> V_8 = V_35 ;
}
if ( V_17 -> V_8 == V_35 ) {
F_2 ( L_7 , V_17 -> V_38 ) ;
F_2 ( L_8 , V_17 -> V_38 ) ;
}
#if F_7 ( V_25 ) && ( V_25 & V_26 )
F_2 ( L_9 , V_17 -> V_38 , V_17 -> V_8 ) ;
#endif
F_2 ( L_10 , V_17 -> V_38 , V_17 -> V_18 ) ;
if ( V_17 -> V_8 == V_35 )
F_2 ( L_11 ) ;
else
F_2 ( L_12 , V_17 -> V_8 ) ;
F_2 ( L_13 ,
V_39 , V_40 , V_41 ) ;
F_12 ( V_17 ) ;
F_2 ( L_14 ) ;
++ V_14 ;
++ V_21 ;
}
return V_21 ;
}
static int F_13 ( struct V_16 * V_42 )
{
F_14 () ;
F_15 ( V_42 ) ;
if ( V_42 -> V_8 )
F_16 ( V_42 -> V_8 , V_42 ) ;
F_17 ( V_42 ) ;
if ( V_42 -> V_43 && V_42 -> V_44 )
F_18 ( V_42 -> V_43 , V_42 -> V_44 ) ;
F_19 ( V_42 ) ;
F_6 ( V_18 ) ;
return 0 ;
}
int F_20 ( struct V_45 * V_46 , struct V_47 * V_48 ,
T_3 V_49 , int * V_50 )
{
V_50 [ 0 ] = 64 ;
V_50 [ 1 ] = 32 ;
V_50 [ 2 ] = V_49 >> 11 ;
return 0 ;
}
static inline int F_21 ( struct V_16 * V_17 , unsigned char * V_51 ,
int V_52 ) {
F_14 () ;
void T_2 * V_53 ;
unsigned char * V_54 = V_51 ;
register int V_4 = V_52 ;
F_15 ( V_17 ) ;
V_53 = V_18 + V_55 ;
#if 0
for (; i; --i) {
while (!(readb(base+T_STATUS_REG_OFFSET) & T_ST_RDY)) barrier();
#else
while ( ! ( F_22 ( V_18 + V_56 ) & V_57 ) ) F_23 () ;
for (; V_4 ; -- V_4 ) {
#endif
* V_54 ++ = F_22 ( V_53 ) ;
}
if ( F_22 ( V_18 + V_56 ) & V_58 ) {
unsigned char V_59 ;
void T_2 * V_60 = V_18 + V_61 ;
V_59 = F_22 ( V_60 ) ;
F_24 ( V_59 | V_62 , V_60 ) ;
F_24 ( V_59 , V_60 ) ;
F_2 ( L_15 ,
V_17 -> V_38 ) ;
return - 1 ;
} else
return 0 ;
}
static inline int F_25 ( struct V_16 * V_17 , unsigned char * V_63 ,
int V_52 ) {
F_14 () ;
void T_2 * V_53 ;
unsigned char * V_64 = V_63 ;
register int V_4 = V_52 ;
F_15 ( V_17 ) ;
V_53 = V_18 + V_55 ;
#if 0
for (; i; --i) {
while (!(readb(base+T_STATUS_REG_OFFSET) & T_ST_RDY)) barrier();
#else
while ( ! ( F_22 ( V_18 + V_56 ) & V_57 ) ) F_23 () ;
for (; V_4 ; -- V_4 ) {
#endif
F_24 ( * V_64 ++ , V_53 ) ;
}
if ( F_22 ( V_18 + V_56 ) & V_58 ) {
unsigned char V_59 ;
void T_2 * V_60 = V_18 + V_61 ;
V_59 = F_22 ( V_60 ) ;
F_24 ( V_59 | V_62 , V_60 ) ;
F_24 ( V_59 , V_60 ) ;
F_2 ( L_16 ,
V_17 -> V_38 ) ;
return - 1 ;
} else
return 0 ;
}
