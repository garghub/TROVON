static int T_1 F_1 ( char * V_1 )
{
static int V_2 = 0 ;
int V_3 ;
int V_4 [ 10 ] ;
F_2 ( V_1 , F_3 ( V_4 ) , V_4 ) ;
if ( V_4 [ 0 ] != 2 )
F_4 ( L_1 ) ;
else
if ( V_2 < V_5 ) {
V_6 [ V_2 ] . V_7 = V_4 [ 1 ] ;
V_6 [ V_2 ] . V_8 = V_4 [ 2 ] ;
for ( V_3 = 0 ; V_3 < V_9 ; ++ V_3 )
if ( V_10 [ V_3 ] . V_7 == V_4 [ 1 ] ) {
V_10 [ V_3 ] . V_11 = 1 ;
break;
}
++ V_2 ;
}
return 1 ;
}
static int T_1 F_5 ( struct V_12 * V_13 )
{
static int V_14 = 0 , V_15 = 0 ;
struct V_16 * V_17 ;
unsigned long V_18 ;
void T_2 * V_19 ;
int V_20 , V_21 ;
for ( V_21 = 0 ; V_14 < V_5 ; ++ V_14 ) {
V_18 = 0 ;
V_19 = NULL ;
if ( V_6 [ V_14 ] . V_7 ) {
V_18 = V_6 [ V_14 ] . V_7 ;
V_19 = F_6 ( V_10 [ V_15 ] . V_7 , 0x2000 ) ;
if ( ! V_19 )
V_18 = 0 ;
} else
for (; ! V_18 && ( V_15 < V_9 ) ; ++ V_15 ) {
#if ( V_22 & V_23 )
F_4 ( L_2 , V_10 [ V_15 ] . V_7 ) ;
#endif
if ( V_10 [ V_15 ] . V_11 )
continue;
V_19 = F_6 ( V_10 [ V_15 ] . V_7 , 0x2000 ) ;
if ( ! V_19 )
continue;
for ( V_20 = 0 ; V_20 < V_24 ; ++ V_20 )
if ( F_7 ( V_19 + V_25 [ V_20 ] . V_26 ,
V_25 [ V_20 ] . string ,
strlen ( V_25 [ V_20 ] . string ) ) ) {
V_18 = V_10 [ V_15 ] . V_7 ;
#if ( V_22 & V_23 )
F_4 ( L_3 ) ;
#endif
goto V_27;
}
F_8 ( V_19 ) ;
}
#if F_9 ( V_22 ) && ( V_22 & V_23 )
F_4 ( L_4 , ( unsigned int ) V_18 ) ;
#endif
if ( ! V_18 )
break;
V_27:
V_17 = F_10 ( V_13 , sizeof( struct V_28 ) ) ;
if( V_17 == NULL )
break;
V_17 -> V_18 = V_18 ;
( (struct V_28 * ) V_17 -> V_29 ) -> V_18 = V_19 ;
F_11 ( V_17 , 0 ) ;
if ( V_6 [ V_14 ] . V_8 != V_30 )
V_17 -> V_8 = V_6 [ V_14 ] . V_8 ;
else
V_17 -> V_8 = F_12 ( V_17 , V_31 ) ;
if ( V_17 -> V_8 == 255 )
V_17 -> V_8 = V_32 ;
if ( V_17 -> V_8 != V_32 )
if ( F_13 ( V_17 -> V_8 , V_33 , 0 , L_5 ,
V_17 ) ) {
F_4 ( L_6 ,
V_17 -> V_34 , V_17 -> V_8 ) ;
V_17 -> V_8 = V_32 ;
}
if ( V_17 -> V_8 == V_32 ) {
F_4 ( L_7 , V_17 -> V_34 ) ;
F_4 ( L_8 , V_17 -> V_34 ) ;
}
#if F_9 ( V_22 ) && ( V_22 & V_23 )
F_4 ( L_9 , V_17 -> V_34 , V_17 -> V_8 ) ;
#endif
++ V_14 ;
++ V_21 ;
}
return V_21 ;
}
static int F_14 ( struct V_16 * V_35 )
{
F_15 () ;
F_16 ( V_35 ) ;
if ( V_35 -> V_8 != V_32 )
F_17 ( V_35 -> V_8 , V_35 ) ;
F_18 ( V_35 ) ;
if ( V_35 -> V_36 && V_35 -> V_37 )
F_19 ( V_35 -> V_36 , V_35 -> V_37 ) ;
F_20 ( V_35 ) ;
F_8 ( V_18 ) ;
return 0 ;
}
static int F_21 ( struct V_38 * V_39 , struct V_40 * V_41 ,
T_3 V_42 , int * V_43 )
{
V_43 [ 0 ] = 64 ;
V_43 [ 1 ] = 32 ;
V_43 [ 2 ] = V_42 >> 11 ;
return 0 ;
}
static inline int F_22 ( struct V_16 * V_17 , unsigned char * V_44 ,
int V_45 ) {
F_15 () ;
void T_2 * V_46 ;
unsigned char * V_47 = V_44 ;
register int V_3 = V_45 ;
F_16 ( V_17 ) ;
V_46 = V_18 + V_48 ;
#if 0
for (; i; --i) {
while (!(readb(base+T_STATUS_REG_OFFSET) & T_ST_RDY)) barrier();
#else
while ( ! ( F_23 ( V_18 + V_49 ) & V_50 ) ) F_24 () ;
for (; V_3 ; -- V_3 ) {
#endif
* V_47 ++ = F_23 ( V_46 ) ;
}
if ( F_23 ( V_18 + V_49 ) & V_51 ) {
unsigned char V_52 ;
void T_2 * V_53 = V_18 + V_54 ;
V_52 = F_23 ( V_53 ) ;
F_25 ( V_52 | V_55 , V_53 ) ;
F_25 ( V_52 , V_53 ) ;
F_4 ( L_10 ,
V_17 -> V_34 ) ;
return - 1 ;
} else
return 0 ;
}
static inline int F_26 ( struct V_16 * V_17 , unsigned char * V_56 ,
int V_45 ) {
F_15 () ;
void T_2 * V_46 ;
unsigned char * V_57 = V_56 ;
register int V_3 = V_45 ;
F_16 ( V_17 ) ;
V_46 = V_18 + V_48 ;
#if 0
for (; i; --i) {
while (!(readb(base+T_STATUS_REG_OFFSET) & T_ST_RDY)) barrier();
#else
while ( ! ( F_23 ( V_18 + V_49 ) & V_50 ) ) F_24 () ;
for (; V_3 ; -- V_3 ) {
#endif
F_25 ( * V_57 ++ , V_46 ) ;
}
if ( F_23 ( V_18 + V_49 ) & V_51 ) {
unsigned char V_52 ;
void T_2 * V_53 = V_18 + V_54 ;
V_52 = F_23 ( V_53 ) ;
F_25 ( V_52 | V_55 , V_53 ) ;
F_25 ( V_52 , V_53 ) ;
F_4 ( L_11 ,
V_17 -> V_34 ) ;
return - 1 ;
} else
return 0 ;
}
