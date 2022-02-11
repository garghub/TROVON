static int T_1 F_1 ( char * V_1 )
{
static int V_2 ;
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
static int V_14 , V_15 ;
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
F_7 ( V_22 , L_2 ,
V_10 [ V_15 ] . V_7 ) ;
if ( V_10 [ V_15 ] . V_11 )
continue;
V_19 = F_6 ( V_10 [ V_15 ] . V_7 , 0x2000 ) ;
if ( ! V_19 )
continue;
for ( V_20 = 0 ; V_20 < V_23 ; ++ V_20 )
if ( F_8 ( V_19 + V_24 [ V_20 ] . V_25 ,
V_24 [ V_20 ] . string ,
strlen ( V_24 [ V_20 ] . string ) ) ) {
V_18 = V_10 [ V_15 ] . V_7 ;
F_7 ( V_22 , L_3 ) ;
goto V_26;
}
F_9 ( V_19 ) ;
}
F_7 ( V_22 , L_4 , ( unsigned int ) V_18 ) ;
if ( ! V_18 )
break;
V_26:
V_17 = F_10 ( V_13 , sizeof( struct V_27 ) ) ;
if( V_17 == NULL )
goto V_28;
V_17 -> V_18 = V_18 ;
( (struct V_27 * ) V_17 -> V_29 ) -> V_18 = V_19 ;
if ( F_11 ( V_17 , V_30 | V_31 ) )
goto V_32;
F_12 ( V_17 ) ;
if ( V_6 [ V_14 ] . V_8 != V_33 )
V_17 -> V_8 = V_6 [ V_14 ] . V_8 ;
else
V_17 -> V_8 = F_13 ( V_17 , V_34 ) ;
if ( V_17 -> V_8 == 255 )
V_17 -> V_8 = V_35 ;
if ( V_17 -> V_8 != V_35 )
if ( F_14 ( V_17 -> V_8 , V_36 , 0 , L_5 ,
V_17 ) ) {
F_4 ( L_6 ,
V_17 -> V_37 , V_17 -> V_8 ) ;
V_17 -> V_8 = V_35 ;
}
if ( V_17 -> V_8 == V_35 ) {
F_4 ( L_7 , V_17 -> V_37 ) ;
F_4 ( L_8 , V_17 -> V_37 ) ;
}
F_7 ( V_22 , L_9 ,
V_17 -> V_37 , V_17 -> V_8 ) ;
++ V_14 ;
++ V_21 ;
}
return V_21 ;
V_32:
F_15 ( V_17 ) ;
V_28:
F_9 ( V_19 ) ;
return V_21 ;
}
static int F_16 ( struct V_16 * V_38 )
{
struct V_27 * V_29 = F_17 ( V_38 ) ;
if ( V_38 -> V_8 != V_35 )
F_18 ( V_38 -> V_8 , V_38 ) ;
F_19 ( V_38 ) ;
F_15 ( V_38 ) ;
F_9 ( V_29 -> V_18 ) ;
return 0 ;
}
static int F_20 ( struct V_39 * V_40 , struct V_41 * V_42 ,
T_3 V_43 , int * V_44 )
{
V_44 [ 0 ] = 64 ;
V_44 [ 1 ] = 32 ;
V_44 [ 2 ] = V_43 >> 11 ;
return 0 ;
}
static inline int F_21 ( struct V_16 * V_17 ,
unsigned char * V_45 , int V_46 )
{
struct V_27 * V_29 = F_17 ( V_17 ) ;
void T_2 * V_47 , * V_18 = V_29 -> V_18 ;
unsigned char * V_48 = V_45 ;
register int V_3 = V_46 ;
V_47 = V_18 + V_49 ;
#if 0
for (; i; --i) {
while (!(readb(base+T_STATUS_REG_OFFSET) & T_ST_RDY)) barrier();
#else
while ( ! ( F_22 ( V_18 + V_50 ) & V_51 ) ) F_23 () ;
for (; V_3 ; -- V_3 ) {
#endif
* V_48 ++ = F_22 ( V_47 ) ;
}
if ( F_22 ( V_18 + V_50 ) & V_52 ) {
unsigned char V_53 ;
void T_2 * V_54 = V_18 + V_55 ;
V_53 = F_22 ( V_54 ) ;
F_24 ( V_53 | V_56 , V_54 ) ;
F_24 ( V_53 , V_54 ) ;
F_4 ( L_10 ,
V_17 -> V_37 ) ;
return - 1 ;
} else
return 0 ;
}
static inline int F_25 ( struct V_16 * V_17 ,
unsigned char * V_57 , int V_46 )
{
struct V_27 * V_29 = F_17 ( V_17 ) ;
void T_2 * V_47 , * V_18 = V_29 -> V_18 ;
unsigned char * V_58 = V_57 ;
register int V_3 = V_46 ;
V_47 = V_18 + V_49 ;
#if 0
for (; i; --i) {
while (!(readb(base+T_STATUS_REG_OFFSET) & T_ST_RDY)) barrier();
#else
while ( ! ( F_22 ( V_18 + V_50 ) & V_51 ) ) F_23 () ;
for (; V_3 ; -- V_3 ) {
#endif
F_24 ( * V_58 ++ , V_47 ) ;
}
if ( F_22 ( V_18 + V_50 ) & V_52 ) {
unsigned char V_53 ;
void T_2 * V_54 = V_18 + V_55 ;
V_53 = F_22 ( V_54 ) ;
F_24 ( V_53 | V_56 , V_54 ) ;
F_24 ( V_53 , V_54 ) ;
F_4 ( L_11 ,
V_17 -> V_37 ) ;
return - 1 ;
} else
return 0 ;
}
