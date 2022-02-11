void F_1 ( void T_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
F_2 ( V_3 , V_1 + V_2 ) ;
}
T_2 F_3 ( void T_1 * V_1 , T_2 V_2 )
{
return F_4 ( V_1 + V_2 ) ;
}
void F_5 ( void T_1 * V_1 , T_2 V_2 , T_3 V_3 )
{
F_6 ( V_1 + V_2 , & V_3 , sizeof( V_3 ) ) ;
}
T_3 F_7 ( void T_1 * V_1 , T_2 V_2 )
{
T_3 V_4 ;
F_8 ( & V_4 , V_1 + V_2 , sizeof( V_4 ) ) ;
return V_4 ;
}
static inline void F_9 ( volatile T_2 T_1 * V_5 ,
T_2 * V_6 , T_4 V_7 )
{
int V_8 , V_9 = V_7 >> 2 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
F_2 ( V_6 [ V_8 ] , V_5 + V_8 ) ;
}
static inline void F_10 ( T_2 * V_5 ,
const volatile T_1 T_2 * V_6 , T_4 V_7 )
{
int V_8 , V_9 = V_7 >> 2 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
V_5 [ V_8 ] = F_4 ( V_6 + V_8 ) ;
}
void F_11 ( struct V_10 * V_11 ,
void T_1 * V_5 , void * V_6 , T_4 V_7 )
{
F_9 ( V_5 , V_6 , V_7 ) ;
}
void F_12 ( struct V_10 * V_11 , void * V_5 ,
void T_1 * V_6 , T_4 V_7 )
{
F_10 ( V_5 , V_6 , V_7 ) ;
}
void F_13 ( struct V_10 * V_11 , T_2 V_2 , T_2 V_3 )
{
unsigned long V_12 ;
F_14 ( & V_11 -> V_13 , V_12 ) ;
V_11 -> V_14 -> V_15 ( V_11 -> V_1 . V_16 , V_2 , V_3 ) ;
F_15 ( & V_11 -> V_13 , V_12 ) ;
}
T_2 F_16 ( struct V_10 * V_11 , T_2 V_2 )
{
unsigned long V_12 ;
T_2 V_4 ;
F_14 ( & V_11 -> V_13 , V_12 ) ;
V_4 = V_11 -> V_14 -> V_17 ( V_11 -> V_1 . V_16 , V_2 ) ;
F_15 ( & V_11 -> V_13 , V_12 ) ;
return V_4 ;
}
void F_17 ( struct V_10 * V_11 , T_2 V_2 , T_3 V_3 )
{
unsigned long V_12 ;
F_14 ( & V_11 -> V_13 , V_12 ) ;
V_11 -> V_14 -> V_18 ( V_11 -> V_1 . V_16 , V_2 , V_3 ) ;
F_15 ( & V_11 -> V_13 , V_12 ) ;
}
T_3 F_18 ( struct V_10 * V_11 , T_2 V_2 )
{
unsigned long V_12 ;
T_3 V_4 ;
F_14 ( & V_11 -> V_13 , V_12 ) ;
V_4 = V_11 -> V_14 -> V_19 ( V_11 -> V_1 . V_16 , V_2 ) ;
F_15 ( & V_11 -> V_13 , V_12 ) ;
return V_4 ;
}
void F_19 ( struct V_10 * V_11 , T_2 V_2 , T_2 V_3 )
{
V_11 -> V_14 -> V_15 ( V_11 -> V_1 . V_16 , V_2 , V_3 ) ;
}
T_2 F_20 ( struct V_10 * V_11 , T_2 V_2 )
{
return V_11 -> V_14 -> V_17 ( V_11 -> V_1 . V_16 , V_2 ) ;
}
void F_21 ( struct V_10 * V_11 , T_2 V_2 , T_3 V_3 )
{
V_11 -> V_14 -> V_18 ( V_11 -> V_1 . V_16 , V_2 , V_3 ) ;
}
T_3 F_22 ( struct V_10 * V_11 , T_2 V_2 )
{
return V_11 -> V_14 -> V_19 ( V_11 -> V_1 . V_16 , V_2 ) ;
}
int F_23 ( struct V_10 * V_11 , T_2 V_2 ,
T_2 V_20 , T_2 V_3 )
{
bool V_21 ;
unsigned int V_22 , V_23 ;
T_2 V_24 ;
V_24 = F_20 ( V_11 , V_2 ) ;
V_22 = V_24 ;
V_23 = ( V_22 & ( ~ V_20 ) ) | ( V_3 & V_20 ) ;
V_21 = ( V_22 != V_23 ) ;
if ( V_21 )
F_19 ( V_11 , V_2 , V_23 ) ;
return V_21 ;
}
int F_24 ( struct V_10 * V_11 , T_2 V_2 ,
T_3 V_20 , T_3 V_3 )
{
bool V_21 ;
T_3 V_22 , V_23 ;
V_22 = F_22 ( V_11 , V_2 ) ;
V_23 = ( V_22 & ( ~ V_20 ) ) | ( V_3 & V_20 ) ;
V_21 = ( V_22 != V_23 ) ;
if ( V_21 )
F_21 ( V_11 , V_2 , V_23 ) ;
return V_21 ;
}
void F_25 ( struct V_10 * V_11 , T_2 V_2 ,
T_2 V_20 , T_2 V_3 )
{
unsigned int V_22 , V_23 ;
T_2 V_24 ;
V_24 = F_20 ( V_11 , V_2 ) ;
V_22 = V_24 ;
V_23 = ( V_22 & ( ~ V_20 ) ) | ( V_3 & V_20 ) ;
F_19 ( V_11 , V_2 , V_23 ) ;
}
int F_26 ( struct V_10 * V_11 , T_2 V_2 ,
T_2 V_20 , T_2 V_3 )
{
unsigned long V_12 ;
bool V_21 ;
F_14 ( & V_11 -> V_13 , V_12 ) ;
V_21 = F_23 ( V_11 , V_2 , V_20 , V_3 ) ;
F_15 ( & V_11 -> V_13 , V_12 ) ;
return V_21 ;
}
int F_27 ( struct V_10 * V_11 , T_2 V_2 ,
T_3 V_20 , T_3 V_3 )
{
unsigned long V_12 ;
bool V_21 ;
F_14 ( & V_11 -> V_13 , V_12 ) ;
V_21 = F_24 ( V_11 , V_2 , V_20 , V_3 ) ;
F_15 ( & V_11 -> V_13 , V_12 ) ;
return V_21 ;
}
void F_28 ( struct V_10 * V_11 , T_2 V_2 ,
T_2 V_20 , T_2 V_3 )
{
unsigned long V_12 ;
F_14 ( & V_11 -> V_13 , V_12 ) ;
F_25 ( V_11 , V_2 , V_20 , V_3 ) ;
F_15 ( & V_11 -> V_13 , V_12 ) ;
}
int F_29 ( struct V_10 * V_25 , T_2 V_2 , T_2 V_20 ,
T_2 V_26 , T_2 time , char * V_27 )
{
T_2 V_28 ;
unsigned long V_29 ;
int V_30 = 0 , V_31 = 500 ;
V_29 = V_32 + F_30 ( time ) ;
while ( ( ( F_20 ( V_25 , V_2 ) & V_20 ) != V_26 )
&& F_31 ( V_32 , V_29 ) ) {
V_30 ++ ;
if ( V_30 > 10 )
V_31 = 5000 ;
F_32 ( V_31 , 2 * V_31 ) ;
}
V_28 = F_20 ( V_25 , V_2 ) ;
if ( ( V_28 & V_20 ) == V_26 ) {
F_33 ( V_25 -> V_33 , L_1 ,
V_28 , V_27 ) ;
return 0 ;
}
F_33 ( V_25 -> V_33 , L_2 ,
V_28 , V_27 ) ;
return - V_34 ;
}
void F_34 ( struct V_10 * V_11 )
{
if ( V_11 -> V_14 -> V_35 )
V_11 -> V_14 -> V_35 ( V_11 ) ;
}
void F_35 ( struct V_10 * V_11 )
{
if ( V_11 -> V_14 -> V_36 )
V_11 -> V_14 -> V_36 ( V_11 ) ;
}
int F_36 ( struct V_10 * V_11 )
{
if ( V_11 -> V_14 -> V_37 )
V_11 -> V_14 -> V_37 ( V_11 ) ;
return 0 ;
}
int F_37 ( struct V_10 * V_11 )
{
if ( V_11 -> V_14 -> V_38 )
return V_11 -> V_14 -> V_38 ( V_11 ) ;
return 0 ;
}
void F_38 ( struct V_10 * V_11 )
{
if ( V_11 -> V_14 -> V_39 )
V_11 -> V_14 -> V_39 ( V_11 ) ;
}
void F_39 ( struct V_10 * V_11 )
{
if ( V_11 -> V_14 -> V_40 )
V_11 -> V_14 -> V_40 ( V_11 ) ;
}
void F_40 ( struct V_10 * V_41 , T_2 V_42 )
{
F_19 ( V_41 , V_43 , V_42 | V_44 ) ;
F_41 ( V_42 ) ;
}
T_2 F_42 ( struct V_10 * V_41 )
{
T_2 V_42 ;
V_42 = F_20 ( V_41 , V_43 ) ;
F_43 ( V_42 ) ;
return V_42 ;
}
int F_44 ( struct V_10 * V_11 , T_2 V_45 , T_4 V_46 ,
T_2 V_47 , T_4 V_48 )
{
V_11 -> V_49 . V_50 = V_11 -> V_1 . V_51 + V_45 ;
V_11 -> V_49 . V_52 = V_11 -> V_1 . V_51 + V_47 ;
V_11 -> V_49 . V_53 = V_46 ;
V_11 -> V_49 . V_54 = V_48 ;
return 0 ;
}
void F_45 ( struct V_10 * V_11 , void * V_55 , T_4 V_7 )
{
T_2 V_8 ;
F_46 ( V_7 ) ;
F_6 ( V_11 -> V_49 . V_52 , V_55 , V_7 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 += 4 )
F_47 ( V_8 , * ( T_2 * ) ( V_55 + V_8 ) ) ;
}
void F_48 ( struct V_10 * V_11 , void * V_55 , T_4 V_7 )
{
T_2 V_8 ;
F_49 ( V_7 ) ;
F_8 ( V_55 , V_11 -> V_49 . V_52 , V_7 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 += 4 )
F_50 ( V_8 , * ( T_2 * ) ( V_55 + V_8 ) ) ;
}
void F_51 ( struct V_10 * V_11 , void * V_55 , T_4 V_7 )
{
T_2 V_8 ;
F_52 ( V_7 ) ;
F_6 ( V_11 -> V_49 . V_50 , V_55 , V_7 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 += 4 )
F_53 ( V_8 , * ( T_2 * ) ( V_55 + V_8 ) ) ;
}
void F_54 ( struct V_10 * V_11 , void * V_55 , T_4 V_7 )
{
T_2 V_8 ;
F_55 ( V_7 ) ;
F_8 ( V_55 , V_11 -> V_49 . V_50 , V_7 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 += 4 )
F_56 ( V_8 , * ( T_2 * ) ( V_55 + V_8 ) ) ;
}
