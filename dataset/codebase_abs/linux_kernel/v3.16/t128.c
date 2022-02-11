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
V_13 -> V_23 = V_24 ;
V_13 -> V_25 = V_26 ;
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
#if ( V_27 & V_28 )
F_2 ( L_3 , V_10 [ V_15 ] . V_7 ) ;
#endif
if ( V_10 [ V_15 ] . V_11 )
continue;
V_19 = F_4 ( V_10 [ V_15 ] . V_7 , 0x2000 ) ;
if ( ! V_19 )
continue;
for ( V_20 = 0 ; V_20 < V_29 ; ++ V_20 )
if ( F_5 ( V_19 + V_30 [ V_20 ] . V_31 ,
V_30 [ V_20 ] . string ,
strlen ( V_30 [ V_20 ] . string ) ) ) {
V_18 = V_10 [ V_15 ] . V_7 ;
#if ( V_27 & V_28 )
F_2 ( L_4 ) ;
#endif
goto V_32;
}
F_6 ( V_19 ) ;
}
#if F_7 ( V_27 ) && ( V_27 & V_28 )
F_2 ( L_5 , ( unsigned int ) V_18 ) ;
#endif
if ( ! V_18 )
break;
V_32:
V_17 = F_8 ( V_13 , sizeof( struct V_33 ) ) ;
if( V_17 == NULL )
break;
V_17 -> V_18 = V_18 ;
( (struct V_33 * ) V_17 -> V_34 ) -> V_18 = V_19 ;
F_9 ( V_17 , 0 ) ;
if ( V_6 [ V_14 ] . V_8 != V_35 )
V_17 -> V_8 = V_6 [ V_14 ] . V_8 ;
else
V_17 -> V_8 = F_10 ( V_17 , V_36 ) ;
if ( V_17 -> V_8 != V_37 )
if ( F_11 ( V_17 -> V_8 , V_38 , 0 , L_2 ,
V_17 ) ) {
F_2 ( L_6 ,
V_17 -> V_39 , V_17 -> V_8 ) ;
V_17 -> V_8 = V_37 ;
}
if ( V_17 -> V_8 == V_37 ) {
F_2 ( L_7 , V_17 -> V_39 ) ;
F_2 ( L_8 , V_17 -> V_39 ) ;
}
#if F_7 ( V_27 ) && ( V_27 & V_28 )
F_2 ( L_9 , V_17 -> V_39 , V_17 -> V_8 ) ;
#endif
F_2 ( L_10 , V_17 -> V_39 , V_17 -> V_18 ) ;
if ( V_17 -> V_8 == V_37 )
F_2 ( L_11 ) ;
else
F_2 ( L_12 , V_17 -> V_8 ) ;
F_2 ( L_13 ,
V_40 , V_41 , V_42 ) ;
F_12 ( V_17 ) ;
F_2 ( L_14 ) ;
++ V_14 ;
++ V_21 ;
}
return V_21 ;
}
static int F_13 ( struct V_16 * V_43 )
{
F_14 () ;
F_15 ( V_43 ) ;
if ( V_43 -> V_8 )
F_16 ( V_43 -> V_8 , V_43 ) ;
F_17 ( V_43 ) ;
if ( V_43 -> V_44 && V_43 -> V_45 )
F_18 ( V_43 -> V_44 , V_43 -> V_45 ) ;
F_19 ( V_43 ) ;
F_6 ( V_18 ) ;
return 0 ;
}
int F_20 ( struct V_46 * V_47 , struct V_48 * V_49 ,
T_3 V_50 , int * V_51 )
{
V_51 [ 0 ] = 64 ;
V_51 [ 1 ] = 32 ;
V_51 [ 2 ] = V_50 >> 11 ;
return 0 ;
}
static inline int F_21 ( struct V_16 * V_17 , unsigned char * V_52 ,
int V_53 ) {
F_14 () ;
void T_2 * V_54 ;
unsigned char * V_55 = V_52 ;
register int V_4 = V_53 ;
F_15 ( V_17 ) ;
V_54 = V_18 + V_56 ;
#if 0
for (; i; --i) {
while (!(readb(base+T_STATUS_REG_OFFSET) & T_ST_RDY)) barrier();
#else
while ( ! ( F_22 ( V_18 + V_57 ) & V_58 ) ) F_23 () ;
for (; V_4 ; -- V_4 ) {
#endif
* V_55 ++ = F_22 ( V_54 ) ;
}
if ( F_22 ( V_18 + V_57 ) & V_59 ) {
unsigned char V_60 ;
void T_2 * V_61 = V_18 + V_62 ;
V_60 = F_22 ( V_61 ) ;
F_24 ( V_60 | V_63 , V_61 ) ;
F_24 ( V_60 , V_61 ) ;
F_2 ( L_15 ,
V_17 -> V_39 ) ;
return - 1 ;
} else
return 0 ;
}
static inline int F_25 ( struct V_16 * V_17 , unsigned char * V_64 ,
int V_53 ) {
F_14 () ;
void T_2 * V_54 ;
unsigned char * V_65 = V_64 ;
register int V_4 = V_53 ;
F_15 ( V_17 ) ;
V_54 = V_18 + V_56 ;
#if 0
for (; i; --i) {
while (!(readb(base+T_STATUS_REG_OFFSET) & T_ST_RDY)) barrier();
#else
while ( ! ( F_22 ( V_18 + V_57 ) & V_58 ) ) F_23 () ;
for (; V_4 ; -- V_4 ) {
#endif
F_24 ( * V_65 ++ , V_54 ) ;
}
if ( F_22 ( V_18 + V_57 ) & V_59 ) {
unsigned char V_60 ;
void T_2 * V_61 = V_18 + V_62 ;
V_60 = F_22 ( V_61 ) ;
F_24 ( V_60 | V_63 , V_61 ) ;
F_24 ( V_60 , V_61 ) ;
F_2 ( L_16 ,
V_17 -> V_39 ) ;
return - 1 ;
} else
return 0 ;
}
