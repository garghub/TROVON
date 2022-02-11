void T_1 F_1 ( struct V_1 * V_2 )
{
}
char * T_1 F_2 ( char * V_3 )
{
return NULL ;
}
void F_3 ( struct V_4 * V_5 )
{
T_2 V_6 ;
F_4 ( V_5 , V_7 , & V_6 ) ;
F_5 ( V_8 L_1 , F_6 ( V_5 ) , V_6 ) ;
F_7 ( V_5 , V_7 , V_6 ) ;
}
int F_8 ( struct V_4 * V_5 , struct V_9 * V_10 ,
enum V_11 V_12 , int V_13 )
{
unsigned long V_14 ;
V_14 = F_9 ( V_10 -> V_15 ) ;
V_10 -> V_15 = F_10 ( V_14 ) ;
if ( F_11 ( V_10 , V_10 -> V_16 , V_10 -> V_17 ,
V_10 -> V_18 - V_10 -> V_16 ,
V_10 -> V_15 ) )
return - V_19 ;
return 0 ;
}
T_3
F_12 ( void * V_20 , const struct V_21 * V_22 ,
T_3 V_23 , T_3 V_24 )
{
T_3 V_25 = V_22 -> V_25 ;
if ( ( V_22 -> V_26 & V_27 ) && ( V_25 & 0x300 ) )
V_25 = ( V_25 + 0x3ff ) & ~ 0x3ff ;
return V_25 ;
}
int F_13 ( struct V_4 * V_5 , int V_28 )
{
T_4 V_29 , V_30 ;
int V_31 ;
struct V_21 * V_32 ;
F_14 ( V_5 , V_33 , & V_29 ) ;
V_30 = V_29 ;
for( V_31 = 0 ; V_31 < 6 ; V_31 ++ ) {
if ( ! ( V_28 & ( 1 << V_31 ) ) )
continue;
V_32 = & V_5 -> V_21 [ V_31 ] ;
if ( ! V_32 -> V_25 && V_32 -> V_34 ) {
F_5 ( V_35 L_2 , F_6 ( V_5 ) ) ;
return - V_36 ;
}
if ( V_32 -> V_26 & V_27 )
V_29 |= V_37 ;
if ( V_32 -> V_26 & V_38 )
V_29 |= V_39 ;
}
if ( V_5 -> V_21 [ V_40 ] . V_25 )
V_29 |= V_39 ;
if ( V_29 != V_30 ) {
F_5 ( L_3 , F_6 ( V_5 ) , V_30 , V_29 ) ;
F_15 ( V_5 , V_33 , V_29 ) ;
}
return 0 ;
}
int F_16 ( struct V_4 * V_5 )
{
V_5 -> V_41 = V_42 ;
return 0 ;
}
int F_17 ( struct V_4 * V_5 , int V_28 )
{
int V_43 ;
if ( ( V_43 = F_13 ( V_5 , V_28 ) ) < 0 )
return V_43 ;
if ( ! V_5 -> V_44 )
F_16 ( V_5 ) ;
return 0 ;
}
int F_18 ( void )
{
struct V_4 * V_5 = NULL ;
int V_31 ;
struct V_21 * V_32 ;
while ( ( V_5 = F_19 ( V_45 , V_45 , V_5 ) ) != NULL ) {
int V_46 = V_5 -> V_46 >> 8 ;
if ( ! V_46 || V_46 == V_47 )
continue;
for( V_31 = 0 ; V_31 < 6 ; V_31 ++ ) {
V_32 = & V_5 -> V_21 [ V_31 ] ;
if ( ! V_32 -> V_25 && V_32 -> V_34 )
F_20 ( V_5 , V_31 ) ;
}
}
return 0 ;
}
