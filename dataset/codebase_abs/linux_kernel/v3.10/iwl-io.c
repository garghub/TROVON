int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 , int V_6 )
{
int V_7 = 0 ;
do {
if ( ( F_2 ( V_2 , V_3 ) & V_5 ) == ( V_4 & V_5 ) )
return V_7 ;
F_3 ( V_8 ) ;
V_7 += V_8 ;
} while ( V_7 < V_6 );
return - V_9 ;
}
T_1 F_4 ( struct V_1 * V_2 , T_1 V_10 )
{
T_1 V_11 = 0x5a5a5a5a ;
unsigned long V_12 ;
if ( F_5 ( V_2 , false , & V_12 ) ) {
V_11 = F_2 ( V_2 , V_10 ) ;
F_6 ( V_2 , & V_12 ) ;
}
return V_11 ;
}
void F_7 ( struct V_1 * V_2 , T_1 V_10 , T_1 V_11 )
{
unsigned long V_12 ;
if ( F_5 ( V_2 , false , & V_12 ) ) {
F_8 ( V_2 , V_10 , V_11 ) ;
F_6 ( V_2 , & V_12 ) ;
}
}
int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 ,
int V_6 )
{
int V_7 = 0 ;
do {
if ( ( F_4 ( V_2 , V_3 ) & V_5 ) == V_5 )
return V_7 ;
F_3 ( V_8 ) ;
V_7 += V_8 ;
} while ( V_7 < V_6 );
return - V_9 ;
}
static inline T_1 F_10 ( struct V_1 * V_2 , T_1 V_13 )
{
T_1 V_14 = F_11 ( V_2 , V_13 ) ;
F_12 ( V_2 -> V_15 , V_13 , V_14 ) ;
return V_14 ;
}
static inline void F_13 ( struct V_1 * V_2 , T_1 V_13 , T_1 V_14 )
{
F_14 ( V_2 -> V_15 , V_13 , V_14 ) ;
F_15 ( V_2 , V_13 , V_14 ) ;
}
T_1 F_16 ( struct V_1 * V_2 , T_1 V_13 )
{
unsigned long V_12 ;
T_1 V_14 = 0x5a5a5a5a ;
if ( F_5 ( V_2 , false , & V_12 ) ) {
V_14 = F_10 ( V_2 , V_13 ) ;
F_6 ( V_2 , & V_12 ) ;
}
return V_14 ;
}
void F_17 ( struct V_1 * V_2 , T_1 V_13 , T_1 V_14 )
{
unsigned long V_12 ;
if ( F_5 ( V_2 , false , & V_12 ) ) {
F_13 ( V_2 , V_13 , V_14 ) ;
F_6 ( V_2 , & V_12 ) ;
}
}
void F_18 ( struct V_1 * V_2 , T_1 V_13 , T_1 V_5 )
{
unsigned long V_12 ;
if ( F_5 ( V_2 , false , & V_12 ) ) {
F_13 ( V_2 , V_13 ,
F_10 ( V_2 , V_13 ) | V_5 ) ;
F_6 ( V_2 , & V_12 ) ;
}
}
void F_19 ( struct V_1 * V_2 , T_1 V_13 ,
T_1 V_4 , T_1 V_5 )
{
unsigned long V_12 ;
if ( F_5 ( V_2 , false , & V_12 ) ) {
F_13 ( V_2 , V_13 ,
( F_10 ( V_2 , V_13 ) & V_5 ) | V_4 ) ;
F_6 ( V_2 , & V_12 ) ;
}
}
void F_20 ( struct V_1 * V_2 , T_1 V_13 , T_1 V_5 )
{
unsigned long V_12 ;
T_1 V_14 ;
if ( F_5 ( V_2 , false , & V_12 ) ) {
V_14 = F_10 ( V_2 , V_13 ) ;
F_13 ( V_2 , V_13 , ( V_14 & ~ V_5 ) ) ;
F_6 ( V_2 , & V_12 ) ;
}
}
